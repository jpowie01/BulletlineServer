/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Bullet_hpp
#define Bullet_hpp

#include <iostream>
#include <SFML/Network.hpp>

#include "Circle.hpp"

class Bullet : public Circle {
private:
    int m_player_id;
    float m_directionX, m_directionY;
    float m_speed;

public:
    // Constructors
    Bullet(int id, float x, float y, float directionX, float directionY, float speed);

    // Core
    void update(sf::Time time);
    void move(float x, float y);

    // Getters
    int getPlayerID();
};

#endif
