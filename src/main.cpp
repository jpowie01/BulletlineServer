/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include <iostream>
#include <SFML/Network.hpp>

#include "core/Player.hpp"
#include "core/Team.hpp"
#include "Definitions.hpp"
#include "helpers/ResourcePath.hpp"
#include "processors/PlayerIntroductionProcessor.hpp"

using namespace std;

int main(int, char const**)
{
    // Preapring socket
    sf::UdpSocket socket;
    
    // Binding socket to a port
    if (socket.bind(SERVER_PORT) != sf::Socket::Done) {
        cout << "Cannot bind into port " << SERVER_PORT << "!\n";
        return 0;
    }
    
    // Print
    sf::IpAddress ipAddress = sf::IpAddress();
    cout << "Local IP Address: " << ipAddress.getLocalAddress().toString() << "\n";
    cout << "Public IP Address: " << ipAddress.getPublicAddress().toString() << "\n";
    cout << "Port: " << SERVER_PORT << "\n";
    cout << "Waiting for incoming data...\n";
    
    // Containers for data
    sf::Packet data;
    sf::IpAddress sender;
    unsigned short port;

    // All players
    int amountOfPlayers = 0;
    Player** players = new Player*[TEAMS * TEAM_SIZE];
    for (int i = 0; i < TEAMS * TEAM_SIZE; i++) {
        players[i] = new Player();
    }

    // All teams
    Team** teams = new Team*[TEAMS];
    for (int i = 0; i < TEAMS; i++) {
        teams[i] = new Team();
    }

    // Main server loop
    while (true) {
        // Receive data
        if (socket.receive(data, sender, port) != sf::Socket::Done) {
            cout << "Error receiving data from " << sender << ":" << port << "\n";
            continue;
        } else {
            cout << "Received data from " << sender << ":" << port << "\n";
        }

        // Process data
        sf::Uint8 header;
        data >> header;
        if (header == NETWORK_PLAYER_INTRODUCTION_HEADER) {
            PlayerIntroductionProcessor::process(socket, data, sender, port, players, teams, amountOfPlayers);
            
//        } else if (header == PLAYER_UPDATE_HEADER) {
//            // Update data
//            int playerID;
//            data >> playerID;
//            players[playerID]->setDataFromPacket(data);
        } else {
            cout << "Unknown header received (" << header << ")\n";
        }
    }
    return 0;
}
