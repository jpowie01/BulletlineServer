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
    // Constructors
    CommonData();
    ~CommonData();

    // Main data
    int winningTeam;
    int amountOfPlayers = 0;
    vector<Bullet*> bullets;
    vector<Obstacle*> obstacles;
    Player** players;
    Team** teams;
    sf::UdpSocket socket;

    // Game flags
    bool gameStarted = false;
    bool gameEnded = false;

    // Mutexes
    sf::Mutex bulletOperationsMutex;
    
    // Methods
    void prepareGameToRestart();
};

#endif
