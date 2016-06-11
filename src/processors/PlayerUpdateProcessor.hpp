/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef PlayerUpdateProcessor_hpp
#define PlayerUpdateProcessor_hpp

#include <iostream>
#include <SFML/Network.hpp>

#include "../core/Processor.hpp"
#include "../core/CommonData.hpp"
#include "../Definitions.hpp"

using namespace std;

class PlayerUpdateProcessor : public Processor {
public:
    void process(sf::Packet data, sf::IpAddress sender, short port, CommonData* commonData);
};

#endif
