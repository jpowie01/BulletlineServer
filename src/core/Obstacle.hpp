/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Obstacle_hpp
#define Obstacle_hpp

#include <cmath>
#include <SFML/Graphics.hpp>
#include "Circle.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

class Obstacle {
private:
    float m_x, m_y;
    float m_width, m_height;
    
public:
    // Constructors
    Obstacle();
    Obstacle(float x, float y, float width, float height);
    
    // Core
    bool checkCollision(Circle* circle);
};

#endif

