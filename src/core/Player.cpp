/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Player.hpp"

Player::Player() {
    this->m_ID = 0;
    this->m_teamID = 0;
    this->m_name = "";
    this->m_x = 0.0;
    this->m_y = 0.0;
    this->m_health = PLAYER_HEALTH;
    this->m_speed = PLAYER_SPEED;
}

Player::Player(string name) {
    this->m_ID = 0;
    this->m_teamID = 0;
    this->m_name = name;
    this->m_x = 0.0;
    this->m_y = 0.0;
    this->m_health = PLAYER_HEALTH;
    this->m_speed = PLAYER_SPEED;
}

void Player::setID(int id) {
    this->m_ID = id;
}

void Player::setTeamID(int id) {
    this->m_teamID = id;
}

void Player::setName(string name) {
    this->m_name = name;
}

void Player::setSpeed(int speed) {
    this->m_speed = speed;
}

void Player::setHealth(int health) {
    this->m_health = health;
}

void Player::setX(float x) {
    this->m_x = x;
}

void Player::setY(float y) {
    this->m_y = y;
}

void Player::setPosition(float x, float y) {
    this->setX(x);
    this->setY(y);
}

void Player::setIPAddress(sf::IpAddress IPAddress) {
    this->m_IPAddress = IPAddress;
}

void Player::setPort(short port) {
    this->m_port = port;
}

int Player::getID() {
    return this->m_ID;
}

int Player::getTeamID() {
    return this->m_teamID;
}

float Player::getX() {
    return this->m_x;
}

float Player::getY() {
    return this->m_y;
}

string Player::getName() {
    return this->m_name;
}

sf::IpAddress Player::getIPAddress() {
    return this->m_IPAddress;
}

short Player::getPort() {
    return this->m_port;
}
