/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "CommonData.hpp"

//================================================================================
// Constructors
//================================================================================

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

    // Creating borders for map
    Obstacle* upper = new Obstacle(0, 0, SCREEN_WIDTH, 20);
    Obstacle* left = new Obstacle(0, 0, 20, SCREEN_HEIGHT);
    Obstacle* right = new Obstacle(SCREEN_WIDTH-20, 0, 20, SCREEN_HEIGHT);
    Obstacle* lower = new Obstacle(0, SCREEN_HEIGHT-80, SCREEN_WIDTH, 80);

    // Adding borders
    obstacles.push_back(upper);
    obstacles.push_back(left);
    obstacles.push_back(right);
    obstacles.push_back(lower);

    // Create all obstacles on map - level one
    Obstacle* obstacle1 = new Obstacle(100, 120, 40, 100);
    Obstacle* obstacle2 = new Obstacle(20, 300, 100, 40);
    Obstacle* obstacle3 = new Obstacle(240, 350, 40, 120);
    Obstacle* obstacle4 = new Obstacle(140, 450, 140, 40);
    Obstacle* obstacle5 = new Obstacle(300, 20, 40, 150);
    Obstacle* obstacle6 = new Obstacle(550, 150, 140, 40);
    Obstacle* obstacle7 = new Obstacle(550, 150, 40, 140);
    Obstacle* obstacle8 = new Obstacle(430, 450, 40, 150);
    Obstacle* obstacle9 = new Obstacle(850, 20, 40, 120);
    Obstacle* obstacle10 = new Obstacle(900, 420, 40, 180);
    Obstacle* obstacle11 = new Obstacle(1000, 300, 220, 40);
    Obstacle* obstacle12 = new Obstacle(1030, 450, 80, 80);
    Obstacle* obstacle13 = new Obstacle(1000, 100, 90, 120);
    Obstacle* obstacle14 = new Obstacle(600, 500, 180, 40);
    Obstacle* obstacle15 = new Obstacle(700, 400, 40, 100);

    // Add all obstacles
    obstacles.push_back(obstacle1);
    obstacles.push_back(obstacle2);
    obstacles.push_back(obstacle3);
    obstacles.push_back(obstacle4);
    obstacles.push_back(obstacle5);
    obstacles.push_back(obstacle6);
    obstacles.push_back(obstacle7);
    obstacles.push_back(obstacle8);
    obstacles.push_back(obstacle9);
    obstacles.push_back(obstacle10);
    obstacles.push_back(obstacle11);
    obstacles.push_back(obstacle12);
    obstacles.push_back(obstacle13);
    obstacles.push_back(obstacle14);
    obstacles.push_back(obstacle15);

    // Binding socket to a port
    if (this->socket.bind(SERVER_PORT) != sf::Socket::Done) {
        cout << "Cannot bind into port " << SERVER_PORT << "!\n";
        return;
    }

    // Log
    sf::IpAddress ipAddress = sf::IpAddress();
    cout << "Local IP Address: " << ipAddress.getLocalAddress().toString() << "\n";
    cout << "Public IP Address: " << ipAddress.getPublicAddress().toString() << "\n";
    cout << "Port: " << SERVER_PORT << "\n";
    cout << "Waiting for incoming data...\n";
}
