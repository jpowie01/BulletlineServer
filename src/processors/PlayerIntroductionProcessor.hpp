/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef PlayerIntroductionProcessor_hpp
#define PlayerIntroductionProcessor_hpp

#include <iostream>
#include <SFML/Network.hpp>

#include "../core/Player.hpp"
#include "../core/Team.hpp"
#include "../Definitions.hpp"

using namespace std;

class PlayerIntroductionProcessor {
public:
    static void process(sf::UdpSocket& socket, sf::Packet data, sf::IpAddress sender, short port, Player** players, Team** teams, int& amountOfPlayers);
};

#endif
