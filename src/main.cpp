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
#include "workers/UpdatePlayersPositionsWorker.hpp"
#include "processors/PlayerIntroductionProcessor.hpp"
#include "processors/PlayerPositionUpdateProcessor.hpp"

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
    PlayerPositionUpdateProcessor* playerPositionUpdateProcessor = new PlayerPositionUpdateProcessor();

    // Create workers
    StartNewGameWorker* startNewGameWorker = new StartNewGameWorker(commonData);
    UpdatePlayersPositionsWorker* updatePlayersPositionsWorker = new UpdatePlayersPositionsWorker(commonData);

    // Run workers
    startNewGameWorker->runConcurrent();
    updatePlayersPositionsWorker->runConcurrent();

    // Main server loop
    while (true) {
        // Receive data
        if (commonData->socket.receive(data, sender, port) != sf::Socket::Done) {
            cout << "Error receiving data from " << sender << ":" << port << "\n";
            continue;
        } else {
            //cout << "Received data from " << sender << ":" << port << "\n";
        }

        // Process data
        sf::Uint8 header;
        data >> header;
        if (header == NETWORK_PLAYER_INTRODUCTION_HEADER) {
            playerIntroductionProcessor->process(data, sender, port, commonData);
        } else if (header == NETWORK_PLAYER_POSITION_UPDATE_HEADER) {
            playerPositionUpdateProcessor->process(data, sender, port, commonData);
        } else {
            cout << "Unknown header received (" << header << ")\n";
        }
    }
    return 0;
}
