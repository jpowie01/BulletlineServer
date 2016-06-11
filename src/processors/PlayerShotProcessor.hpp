/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef PlayerShotProcessor_hpp
#define PlayerShotProcessor_hpp

#include <iostream>
#include <SFML/Network.hpp>

#include "../core/Processor.hpp"
#include "../core/CommonData.hpp"
#include "../core/Bullet.hpp"
#include "../Definitions.hpp"

using namespace std;

class PlayerShotProcessor : public Processor {
public:
    void process(sf::Packet data, sf::IpAddress sender, short port, CommonData* commonData);
};

#endif
