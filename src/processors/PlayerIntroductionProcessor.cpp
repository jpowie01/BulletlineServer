/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "PlayerIntroductionProcessor.hpp"

void PlayerIntroductionProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData* commonData) {
    // Unpack data
    string name;
    data >> name;

    // Prepare player
    Player* player = new Player(name);
    player->setID(commonData->amountOfPlayers);
    player->setIPAddress(sender);
    player->setPort(port);

    // Add player
    commonData->players[commonData->amountOfPlayers] = player;
    commonData->amountOfPlayers++;

    // Add player to smallest team
    int smallestTeam = BLUE_TEAM;
    for (int i = 0; i < TEAMS; i++) {
        if (commonData->teams[i]->getSize() < commonData->teams[smallestTeam]->getSize()) {
            smallestTeam = i;
        }
    }
    commonData->teams[smallestTeam]->addPlayer(player);
    player->setTeamID(smallestTeam);

    // Prepare response to player
    sf::Packet response;
    sf::Uint8 playerID = player->getID();
    sf::Uint8 playerTeamID = player->getTeamID();
    sf::Uint8 playersSize = commonData->amountOfPlayers;
    sf::Uint8 header = NETWORK_JOINED_GAME_HEADER;
    response << header;
    response << playerID;
    response << playerTeamID;
    response << playersSize;
    for (int i = 0; i < commonData->amountOfPlayers; i++) {
        if (player->getID() != i) {
            playerID = commonData->players[i]->getID();
            playerTeamID = commonData->players[i]->getTeamID();
            response << playerID;
            response << playerTeamID;
            response << commonData->players[i]->getName();
        }
    }

    // Send response to player
    if (commonData->socket.send(response, player->getIPAddress(), player->getPort()) != sf::Socket::Done) {
        cout << "Error sending JOINED_GAME to player " << player->getName() << "!\n";
    } else {
        cout << "JOINED_GAME send to " << player->getName() << " (ID: " << player->getID() << ")" << "\n";
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
    for (int i = 0; i < commonData->amountOfPlayers; i++) {
        if (i != player->getID()) {
            // Send
            if (commonData->socket.send(information, commonData->players[i]->getIPAddress(), commonData->players[i]->getPort()) != sf::Socket::Done) {
                cout << "Error sending PLAYER_JOINED to player " << commonData->players[i]->getName() << "!\n";
            } else {
                cout << "PLAYER_JOINED send to " << commonData->players[i]->getName() << " (ID: " << commonData->players[i]->getID() << ")" << "\n";
            }
        }
    }
}
