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
                    if (commonData->bullets[i]->getPlayerID() != commonData->players[j]->getID() && commonData->players[j]->checkCollision(commonData->bullets[i])) {
                        sf::Lock lock(commonData->bulletOperationsMutex);
                        delete commonData->bullets[i];
                        commonData->bullets.erase(commonData->bullets.begin() + i);
                        i--;
                        break;
                    }
                }
            }
        }

        // Restart time
        time = clock.getElapsedTime();
        clock.restart();

        // Delay
        sf::sleep(sf::seconds(0.005f));
    }
}
