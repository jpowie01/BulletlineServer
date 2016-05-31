/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Circle.hpp"

//================================================================================
// Constructors
//================================================================================

Circle::Circle() {
    this->m_x = 0.0f;
    this->m_y = 0.0f;
    this->m_radius = 0.0f;
}

Circle::Circle(float x, float y, float radius) {
    this->m_x = x - radius;
    this->m_y = y - radius;
    this->m_radius = radius;
}

//================================================================================
// Getters
//================================================================================

float Circle::getX() {
    return this->m_x;
}

float Circle::getY() {
    return this->m_y;
}

float Circle::getRadius() {
    return this->m_radius;
}

//================================================================================
// Setters
//================================================================================

void Circle::setX(float x) {
    this->m_x = x;
}

void Circle::setY(float y) {
    this->m_y = y;
}

void Circle::setPosition(float x, float y) {
    this->m_x = x;
    this->m_y = y;
}

void Circle::setRadius(float radius) {
    this->m_radius = radius;
}

//================================================================================
// Collisions
//================================================================================

bool Circle::checkCollision(Circle* circle) {
    float differenceX = circle->getX() + circle->getRadius() - this->getX() - this->getRadius();
    float differenceY = circle->getY() + circle->getRadius() - this->getY() - this->getRadius();
    float distance = sqrt(differenceX * differenceX + differenceY * differenceY);
    if (distance <= circle->getRadius() + this->getRadius()) {
        return true;
    } else {
        return false;
    }
}
