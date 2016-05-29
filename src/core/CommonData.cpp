/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "CommonData.hpp"

CommonData::CommonData() {
    // Prepare all players
    this->players = new Player*[TEAMS * TEAM_SIZE];
    for (int i = 0; i < TEAMS * TEAM_SIZE; i++) {
        this->players[i] = new Player();
    }

    // Prepare all teams
    this->teams = new Team*[TEAMS];
    for (int i = 0; i < TEAMS; i++) {
        this->teams[i] = new Team();
    }

    // Binding socket to a port
    if (this->socket.bind(SERVER_PORT) != sf::Socket::Done) {
        cout << "Cannot bind into port " << SERVER_PORT << "!\n";
        return;
    }

    // Log
    sf::IpAddress ipAddress = sf::IpAddress();
    cout << "Local IP Address: " << ipAddress.getLocalAddress().toString() << "\n";
    //cout << "Public IP Address: " << ipAddress.getPublicAddress().toString() << "\n";
    cout << "Port: " << SERVER_PORT << "\n";
    cout << "Waiting for incoming data...\n";
}
