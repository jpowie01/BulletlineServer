/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Team_hpp
#define Team_hpp

#include <iostream>
#include <SFML/Network.hpp>

#include "Player.hpp"
#include "../Definitions.hpp"

using namespace std;

class Team {
private:
    vector<Player*> m_players;

public:
    // Constructors
    Team();
    
    // Core
    bool isFull();
    int addPlayer(Player* player);
    
    // Getters
    int getSize();
};

#endif
