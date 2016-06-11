/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "PlayerShotProcessor.hpp"

void PlayerShotProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData *commonData) {
    // Unpack data
    sf::Uint8 id;
    float x, y;
    float directionX, directionY;
    float speed;
    data >> id >> x >> y >> directionX >> directionY >> speed;
    
    // Set data
    Bullet* bullet = new Bullet((int)id, x, y, directionX, directionY, speed);
    {
        sf::Lock lock(commonData->bulletOperationsMutex);
        commonData->bullets.push_back(bullet);
    }
    
    // Send information to other players
    sf::Packet information;
    sf::Uint8 header = NETWORK_NEW_BULLET_HEADER;
    information << header << id << x << y << directionX << directionY << speed;
    for (int i = 0; i < commonData->amountOfPlayers; i++) {
        if (i != (int)id) {
            // Send
            if (commonData->socket.send(information, commonData->players[i]->getIPAddress(), commonData->players[i]->getPort()) != sf::Socket::Done) {
                cout << "Error sending NEW_BULLET to player " << commonData->players[i]->getName() << "!\n";
            } else {
                //cout << "NEW_BULLET send to " << commonData->players[i]->getName() << " (ID: " << commonData->players[i]->getID() << ")" << "\n";
            }
        }
    }
}
