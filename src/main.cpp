/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include <iostream>
#include <SFML/Network.hpp>

#include "Definitions.hpp"
#include "core/CommonData.hpp"
#include "helpers/ResourcePath.hpp"
#include "workers/StartNewGameWorker.hpp"
#include "processors/PlayerIntroductionProcessor.hpp"

using namespace std;

int main(int, char const**)
{
    // Create common data
    CommonData* commonData = new CommonData();
    
    // Containers for data
    sf::Packet data;
    sf::IpAddress sender;
    unsigned short port;

    // Create processors
    PlayerIntroductionProcessor* playerIntroductionProcessor = new PlayerIntroductionProcessor();

    // Create workers
    StartNewGameWorker* startNewGameWorker = new StartNewGameWorker(commonData);

    // Run workers
    startNewGameWorker->runConcurrent();

    // Main server loop
    while (true) {
        // Receive data
        if (commonData->socket.receive(data, sender, port) != sf::Socket::Done) {
            cout << "Error receiving data from " << sender << ":" << port << "\n";
            continue;
        } else {
            cout << "Received data from " << sender << ":" << port << "\n";
        }

        // Process data
        sf::Uint8 header;
        data >> header;
        if (header == NETWORK_PLAYER_INTRODUCTION_HEADER) {
            playerIntroductionProcessor->process(data, sender, port, commonData);
            
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
