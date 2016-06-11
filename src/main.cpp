/*
 * Bulletline
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
#include "workers/UpdatePlayersWorker.hpp"
#include "workers/GameSimulationWorker.hpp"
#include "processors/PlayerIntroductionProcessor.hpp"
#include "processors/PlayerUpdateProcessor.hpp"
#include "processors/PlayerShotProcessor.hpp"

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
    PlayerUpdateProcessor* playerUpdateProcessor = new PlayerUpdateProcessor();
    PlayerShotProcessor* playerShotProcessor = new PlayerShotProcessor();

    // Create workers
    StartNewGameWorker* startNewGameWorker = new StartNewGameWorker(commonData);
    UpdatePlayersWorker* updatePlayersWorker = new UpdatePlayersWorker(commonData);
    GameSimulationWorker* gameSimulationWorker = new GameSimulationWorker(commonData);

    // Run workers
    startNewGameWorker->runConcurrent();
    updatePlayersWorker->runConcurrent();
    gameSimulationWorker->runConcurrent();

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
        } else if (header == NETWORK_PLAYER_UPDATE_HEADER) {
            playerUpdateProcessor->process(data, sender, port, commonData);
        } else if (header == NETWORK_PLAYER_SHOT_HEADER) {
            playerShotProcessor->process(data, sender, port, commonData);
        } else {
            cout << "Unknown header received (" << header << ")\n";
        }
    }
    return 0;
}
