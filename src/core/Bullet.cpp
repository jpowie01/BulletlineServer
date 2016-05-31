/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Bullet.hpp"

//================================================================================
// Constructors
//================================================================================

Bullet::Bullet(int id, float x, float y, float directionX, float directionY, float speed) {
    this->m_player_id = id;
    this->m_x = x;
    this->m_y = y;
    this->m_radius = 2.0f;
    this->m_directionX = directionX;
    this->m_directionY = directionY;
    this->m_speed = speed;
}

//================================================================================
// Core
//================================================================================

void Bullet::update(sf::Time time) {
    float movement = this->m_speed * time.asSeconds();
    float movementX = movement * this->m_directionX;
    float movementY = movement * this->m_directionY;
    this->move(movementX, movementY);
}

void Bullet::move(float x, float y) {
    this->m_x += x;
    this->m_y += y;
}

//================================================================================
// Getters
//================================================================================

int Bullet::getPlayerID() {
    return this->m_player_id;
}
