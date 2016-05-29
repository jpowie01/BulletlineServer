/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef CommonData_hpp
#define CommonData_hpp

#include <iostream>

#include "../Definitions.hpp"
#include "Player.hpp"
#include "Team.hpp"

using namespace std;

class CommonData {
public:
    CommonData();
    ~CommonData();

    bool gameStarted = false;
    int amountOfPlayers = 0;
    Player** players;
    Team** teams;

    sf::UdpSocket socket;
};

#endif
