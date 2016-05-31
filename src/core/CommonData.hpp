/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef CommonData_hpp
#define CommonData_hpp

#include <iostream>
#include <vector>

#include "../Definitions.hpp"
#include "Player.hpp"
#include "Team.hpp"
#include "Bullet.hpp"
#include "Obstacle.hpp"

using namespace std;

class CommonData {
public:
    CommonData();
    ~CommonData();

    bool gameStarted = false;

    int amountOfPlayers = 0;
    vector<Bullet*> bullets;
    vector<Obstacle*> obstacles;
    Player** players;
    Team** teams;

    sf::UdpSocket socket;
    
    sf::Mutex bulletOperationsMutex;
};

#endif
