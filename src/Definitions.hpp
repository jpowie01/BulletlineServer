/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Definitions_hpp
#define Definitions_hpp

// Client definitions
#define SCREEN_WIDTH        1200
#define SCREEN_HEIGHT       680

// Core definitions
#define SERVER_PORT         54000

// Player settings
#define PLAYER_SPEED        150
#define PLAYER_HEALTH       100

// Players starting positions
#define LEFT_STARTING_POSITION      35.0
#define RIGHT_STARTING_POSITION     1135.0
#define TOP_STARTING_POSITION       35.0
#define BOTTOM_STARTING_POSITION    550.0

// Team settings
#define TEAMS               2
#define BLUE_TEAM           0
#define RED_TEAM            1
#define TEAM_SIZE           2

// Network headers
#define NETWORK_PLAYER_INTRODUCTION_HEADER              1
#define NETWORK_JOINED_GAME_HEADER                      2
#define NETWORK_PLAYER_JOINED_HEADER                    3
#define NETWORK_START_GAME_HEADER                       4
#define NETWORK_PLAYER_UPDATE_HEADER                    5
#define NETWORK_ALL_PLAYERS_UPDATE_HEADER               6
#define NETWORK_PLAYER_SHOT_HEADER                      7
#define NETWORK_NEW_BULLET_HEADER                       8
#define NETWORK_PLAYER_IS_DEAD_HEADER                   9
#define NETWORK_END_OF_THE_GAME_HEADER                  10

#endif
