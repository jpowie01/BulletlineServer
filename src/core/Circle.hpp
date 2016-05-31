/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <math.h>
#include <SFML/Graphics.hpp>

class Circle {
protected:
    // Data
    float m_x, m_y, m_radius;
    
public:
    // Constructors
    Circle();
    Circle(float x, float y, float radius);
    
    // Getters
    float getX();
    float getY();
    float getRadius();
    
    // Setters
    void setX(float x);
    void setY(float y);
    void setPosition(float x, float y);
    void setRadius(float radius);
    
    // Collision
    bool checkCollision(Circle* circle);
};

#endif
