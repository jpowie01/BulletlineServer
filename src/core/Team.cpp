/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Team.hpp"

//================================================================================
// Contructors
//================================================================================

Team::Team() {}

//================================================================================
// Core
//================================================================================

bool Team::isFull() {
    return this->m_players.size() == TEAM_SIZE;
}

bool Team::isDead() {
    for (int i = 0; i < this->m_players.size(); i++) {
        if (!this->m_players[i]->isDead()) {
            return false;
        }
    }
    return true;
}

int Team::addPlayer(Player* player) {
    int id = (int)this->m_players.size();
    this->m_players.push_back(player);
    return id;
}

//================================================================================
// Getters
//================================================================================

int Team::getSize() {
    return (int)this->m_players.size();
}
