/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <SFML/Network.hpp>

#include "../Definitions.hpp"

using namespace std;

class Player {
private:
    int m_ID;
    int m_teamID;
    string m_name;
    int m_speed, m_health;
    double m_x, m_y;
    sf::IpAddress m_IPAddress;
    short m_port;

public:
    Player();
    Player(string name);
    //sf::Packet prepareToSend(int header);
    //void setDataFromPacket(sf::Packet packet);
    
    // Setters
    void setID(int id);
    void setTeamID(int id);
    void setName(string name);
    void setSpeed(int speed);
    void setHealth(int health);
    void setX(double x);
    void setY(double y);
    void setIPAddress(sf::IpAddress IPAddress);
    void setPort(short port);
    
    // Getters
    int getID();
    int getTeamID();
    string getName();
    sf::IpAddress getIPAddress();
    short getPort();
};

#endif
