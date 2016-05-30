/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "PlayerPositionUpdateProcessor.hpp"

void PlayerPositionUpdateProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData *commonData) {
    // Unpack data
    sf::Uint8 id;
    float x, y;
    data >> id >> x >> y;

    // Set data
    commonData->players[(int)id]->setX(x);
    commonData->players[(int)id]->setY(y);
}
