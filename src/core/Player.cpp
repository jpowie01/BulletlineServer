/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Player.hpp"

//================================================================================
// Contructors
//================================================================================

Player::Player() {
    this->m_dead = false;
    this->m_ID = 0;
    this->m_teamID = 0;
    this->m_name = "";
    this->m_x = 0.0;
    this->m_y = 0.0;
    this->m_radius = 15.0f;
    this->m_health = PLAYER_HEALTH;
    this->m_speed = PLAYER_SPEED;
}

Player::Player(string name) {
    this->m_dead = false;
    this->m_ID = 0;
    this->m_teamID = 0;
    this->m_name = name;
    this->m_x = 0.0;
    this->m_y = 0.0;
    this->m_radius = 15.0f;
    this->m_health = PLAYER_HEALTH;
    this->m_speed = PLAYER_SPEED;
}

Player::~Player() {}

//================================================================================
// Setters
//================================================================================

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
    if (this->m_health <= 0) {
        this->m_health = 0;
        this->setDead();
    }
}

void Player::setIPAddress(sf::IpAddress IPAddress) {
    this->m_IPAddress = IPAddress;
}

void Player::setPort(short port) {
    this->m_port = port;
}

void Player::setDead() {
    this->m_dead = true;
}

//================================================================================
// Getters
//================================================================================

int Player::getID() {
    return this->m_ID;
}

int Player::getTeamID() {
    return this->m_teamID;
}

string Player::getName() {
    return this->m_name;
}

int Player::getHealth() {
    return this->m_health;
}

sf::IpAddress Player::getIPAddress() {
    return this->m_IPAddress;
}

short Player::getPort() {
    return this->m_port;
}

bool Player::isDead() {
    return this->m_dead;
}
