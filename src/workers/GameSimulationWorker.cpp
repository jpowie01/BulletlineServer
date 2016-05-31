/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "GameSimulationWorker.hpp"

GameSimulationWorker::GameSimulationWorker(CommonData* commonData) : Worker(commonData) {}

void GameSimulationWorker::run() {
    // Time
    sf::Clock clock;
    sf::Time time = sf::seconds(0.0f);
    
    // Main loop
    while (true) {
        // Check if game is running
        if (commonData->gameStarted) {
            // Update bullets
            for (int i = 0; i < commonData->bullets.size(); i++) {
                // Update positions
                commonData->bullets[i]->update(time);

                // Deleted flag
                bool deleted = false;

                // Check if bullet has collision with obstacles
                for (int j = 0; j < commonData->obstacles.size(); j++) {
                    if (commonData->obstacles[j]->checkCollision(commonData->bullets[i])) {
                        // Delete bullet
                        sf::Lock lock(commonData->bulletOperationsMutex);
                        delete commonData->bullets[i];
                        commonData->bullets.erase(commonData->bullets.begin() + i);
                        i--;
                        deleted = true;
                        break;
                    }
                }
                if (deleted) {
                    continue;
                }

                // Check if bullet has collision with players
                for (int j = 0; j < commonData->amountOfPlayers; j++) {
                    if (!commonData->players[j]->isDead() &&
                        commonData->bullets[i]->getPlayerID() != commonData->players[j]->getID() &&
                        commonData->players[j]->checkCollision(commonData->bullets[i])) {

                        // Change player health
                        commonData->players[j]->setHealth(commonData->players[j]->getHealth() - 1);
                        
                        // Check if player is dead
                        if (commonData->players[j]->isDead()) {
                            // Prepare data
                            sf::Packet data;
                            sf::Uint8 header = NETWORK_PLAYER_IS_DEAD_HEADER;
                            sf::Uint8 id = commonData->players[j]->getID();
                            data << header << id;
                            
                            // Send data
                            for (int k = 0; k < commonData->amountOfPlayers; k++) {
                                if (commonData->socket.send(data, commonData->players[k]->getIPAddress(), commonData->players[k]->getPort()) != sf::Socket::Done) {
                                    cout << "Error sending PLAYER_IS_DEAD to player " << commonData->players[k]->getName() << "!\n";
                                } else {
                                    cout << "PLAYER_IS_DEAD send to " << commonData->players[k]->getName() << " (ID: " << commonData->players[k]->getID() << ")" << "\n";
                                }
                            }
                        }

                        // Delete bullet
                        sf::Lock lock(commonData->bulletOperationsMutex);
                        delete commonData->bullets[i];
                        commonData->bullets.erase(commonData->bullets.begin() + i);
                        i--;
                        break;
                    }
                }
            }

            // Check if all team is dead, send information to all players and end game
            for (int i = 0; i < commonData->amountOfPlayers; i++) {
                
            }
        }

        // Restart time
        time = clock.getElapsedTime();
        clock.restart();

        // Delay
        sf::sleep(sf::seconds(0.005f));
    }
}
