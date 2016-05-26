/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "PlayerIntroductionProcessor.hpp"

void PlayerIntroductionProcessor::process(sf::UdpSocket& socket, sf::Packet data, sf::IpAddress sender, short port, Player** players, Team** teams, int& amountOfPlayers) {
    // Unpack data
    string name;
    data >> name;

    // Prepare player
    Player* player = new Player(name);
    player->setID(amountOfPlayers);
    player->setIPAddress(sender);
    player->setPort(port);

    // Add player
    players[amountOfPlayers] = player;
    amountOfPlayers++;

    // Add player to smallest team
    int smallestTeam = BLUE_TEAM;
    for (int i = 0; i < TEAMS; i++) {
        if (teams[i]->getSize() < teams[smallestTeam]->getSize()) {
            smallestTeam = i;
        }
    }
    teams[smallestTeam]->addPlayer(player);
    player->setTeamID(smallestTeam);

    // Log
    cout << "New player added to the game (ID: " << player->getID() << " Team ID: " << player->getTeamID() << " Name: " << player->getName() << ")\n";

    // Prepare response to player
    sf::Packet response;
    sf::Uint8 playerID = player->getID();
    sf::Uint8 playerTeamID = player->getTeamID();
    sf::Uint8 playersSize = amountOfPlayers;
    sf::Uint8 header = NETWORK_PLAYER_JOINED_GAME_HEADER;
    response << header;
    response << playerID;
    response << playerTeamID;
    response << playersSize;
    for (int i = 0; i < amountOfPlayers; i++) {
        if (player->getID() != i) {
            playerID = players[i]->getID();
            playerTeamID = players[i]->getTeamID();
            response << playerID;
            response << playerTeamID;
            response << players[i]->getName();
        }
    }

    // Send response to player
    if (socket.send(response, player->getIPAddress(), player->getPort()) != sf::Socket::Done) {
        cout << "Error sending data to player!\n";
    } else {
        cout << "PLAYER_JOINED_GAME send to " << player->getName() << " (ID: " << player->getID() << ")" << "\n";
    }

    // Send response to other players
    sf::Packet information;
    header = NETWORK_PLAYER_JOINED_HEADER;
    playerID = player->getID();
    playerTeamID = player->getTeamID();
    information << header;
    information << playerID;
    information << playerTeamID;
    information << player->getName();
    for (int i = 0; i < amountOfPlayers; i++) {
        if (i != player->getID()) {
            // Send
            if (socket.send(information, players[i]->getIPAddress(), players[i]->getPort()) != sf::Socket::Done) {
                cout << "Error sending data to player!\n";
            } else {
                cout << "PLAYER_JOINED send to " << players[i]->getName() << " (ID: " << players[i]->getID() << ")" << "\n";
            }
        }
    }
}
