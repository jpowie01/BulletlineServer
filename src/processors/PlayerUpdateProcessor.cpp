/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "PlayerUpdateProcessor.hpp"

void PlayerUpdateProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData *commonData) {
    // Unpack data
    sf::Uint8 id;
    float x, y;
    data >> id >> x >> y;

    // Set data
    commonData->players[(int)id]->setX(x);
    commonData->players[(int)id]->setY(y);
}
