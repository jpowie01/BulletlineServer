/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Obstacle.hpp"
#include <SFML/Graphics.hpp>

//================================================================================
// Contructors
//================================================================================

Obstacle::Obstacle() {
    this->m_x = 0.0f;
    this->m_y = 0.0f;
    this->m_width = 0.0f;
    this->m_height = 0.0f;
}

Obstacle::Obstacle(float x, float y, float width, float height) {
    this->m_x = x;
    this->m_y = y;
    this->m_width = width;
    this->m_height = height;
}

//================================================================================
// Core
//================================================================================

bool Obstacle::checkCollision(Circle* circle) {
    float x = circle->getX();
    float y = circle->getY();
    float r = circle->getRadius();
    
    float distanceX = fabs(x - this->m_width/2 - this->m_x + r);
    float distanceY = fabs(y - this->m_height/2 - this->m_y + r);
    
    if (distanceX > this->m_width/2 + r) return false;
    if (distanceY > this->m_height/2 + r) return false;
    
    if (distanceX <= this->m_width/2) return true;
    if (distanceY <= this->m_height/2) return true;
    
    float cornerDistance = (distanceX - this->m_width/2) * (distanceX - this->m_width/2) +
    (distanceY - this->m_height/2) * (distanceY - this->m_height/2);
    
    return (cornerDistance <= r * r);
}
