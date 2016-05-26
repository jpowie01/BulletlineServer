/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Team.hpp"


Team::Team() {}

bool Team::isFull() {
    return this->m_players.size() == TEAM_SIZE;
}

int Team::getSize() {
    return (int)this->m_players.size();
}

int Team::addPlayer(Player* player) {
    int id = (int)this->m_players.size();
    this->m_players.push_back(player);
    return id;
}
