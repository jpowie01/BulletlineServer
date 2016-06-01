/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "UpdatePlayersWorker.hpp"

UpdatePlayersWorker::UpdatePlayersWorker(CommonData* commonData) : Worker(commonData) {}

void UpdatePlayersWorker::run() {
    // Main loop
    while (true) {
        // Send positions only when game has started
        if (this->commonData->gameStarted && !this->commonData->gameEnded) {
            // Prepare data
            sf::Packet data;
            sf::Uint8 header = NETWORK_ALL_PLAYERS_UPDATE_HEADER;
            data << header;
            for (int i = 0; i < commonData->amountOfPlayers; i++) {
                Player* player = commonData->players[i];
                sf::Uint8 id = player->getID();
                sf::Uint8 health = player->getHealth();
                data << id << player->getX() << player->getY() << health;
            }

            // Send data
            for (int i = 0; i < commonData->amountOfPlayers; i++) {
                if (commonData->socket.send(data, commonData->players[i]->getIPAddress(), commonData->players[i]->getPort()) != sf::Socket::Done) {
                    cout << "Error sending ALL_PLAYERS_UPDATE to player " << commonData->players[i]->getName() << "!\n";
                } else {
                    //cout << "ALL_PLAYERS_UPDATE send to " << commonData->players[i]->getName() << " (ID: " << commonData->players[i]->getID() << ")" << "\n";
                }
            }

            // Delay
            sf::sleep(sf::seconds(0.01f));
        } else {
            // Delay
            sf::sleep(sf::seconds(0.1f));
        }
    }
}
