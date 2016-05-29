/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "StartNewGameWorker.hpp"

StartNewGameWorker::StartNewGameWorker(CommonData* commonData) : Worker(commonData) {}

void StartNewGameWorker::run() {
    // Timer
    bool counting = false;
    sf::Clock clock;
    sf::Time fiveteenSeconds = sf::seconds(15.0f);

    // Main loop
    while (true) {
        // End while game started
        if (commonData->gameStarted == true) {
            break;
        }

        // Check if there are 2 or 4 players available
        if (commonData->amountOfPlayers == 2 || commonData->amountOfPlayers == 4) {
            // Restart clock and start counting time
            if (counting == false) {
                clock.restart();
            }
            counting = true;
        } else {
            // Amount of players has changed since last time
            counting = false;
        }

        // Check if time has ended
        if (counting && clock.getElapsedTime().asSeconds() >= fiveteenSeconds.asSeconds() - 3.0f) {
            // Place players in corners
            this->commonData->players[0]->setPosition(30.0, 100.0);

            // Prepare 'start' information
            sf::Packet information;
            sf::Uint8 header = NETWORK_START_GAME_HEADER;
            information << header;

            // Add players positions
            for (int i = 0; i < commonData->amountOfPlayers; i++) {
                // Prepare data
                sf::Uint8 id;
                sf::Uint32 x, y;
                id = commonData->players[i]->getID();
                if (commonData->players[i]->getTeamID() == BLUE_TEAM) {
                    x = LEFT_STARTING_POSITION;
                } else {
                    x = RIGHT_STARTING_POSITION;
                }
                if (commonData->players[i]->getID() % 2 == 0) {
                    y = TOP_STARTING_POSITION;
                } else {
                    y = BOTTOM_STARTING_POSITION;
                }

                // Add data
                information << id << x << y;
            }

            // Send information
            for (int i = 0; i < commonData->amountOfPlayers; i++) {
                if (commonData->socket.send(information, commonData->players[i]->getIPAddress(), commonData->players[i]->getPort()) != sf::Socket::Done) {
                    cout << "Error sending NETWORK_START_GAME_HEADER to player " << commonData->players[i]->getName() << "!\n";
                } else {
                    cout << "NETWORK_START_GAME_HEADER send to " << commonData->players[i]->getName() << " (ID: " << commonData->players[i]->getID() << ")" << "\n";
                }
            }

            // Game has started
            commonData->gameStarted = true;
        }

        // Delay
        sf::sleep(sf::seconds(0.1f));
    }
}
