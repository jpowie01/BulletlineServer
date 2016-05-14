/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include <iostream>
#include <SFML/Network.hpp>

#include "Definitions.hpp"
#include "helpers/ResourcePath.hpp"

using namespace std;

int main(int, char const**)
{
    // Preapring socket
    sf::UdpSocket socket;
    
    // Binding socket to a port
    if (socket.bind(SERVER_PORT) != sf::Socket::Done) {
        cout << "Cannot bind into port " << SERVER_PORT << "!\n";
        return 0;
    }
    
    // Print
    sf::IpAddress ipAddress = sf::IpAddress();
    cout << "Local IP Address: " << ipAddress.getLocalAddress().toString() << "\n";
    cout << "Public IP Address: " << ipAddress.getPublicAddress().toString() << "\n";
    cout << "Port: " << SERVER_PORT << "\n";
    cout << "Waiting for incoming data...\n";
    
    // Containers for data
    sf::Packet data;
    sf::IpAddress sender;
    unsigned short port;
    
    // Main server loop
    while (true) {
        // Receive data
        if (socket.receive(data, sender, port) != sf::Socket::Done) {
            cout << "Error receiving data from " << sender << ":" << port << "\n";
            continue;
        }
        
        // Process data
        sf::Uint8 header;
        data >> header;
        if (header == PLAYER_HEADER) {
            // Unpack data
            float x, y;
            data >> x >> y;
            
            // Process data
            printf("x: %f, y: %f\n", x, y);
        } else {
            printf("Unknown header!\n");
        }
    }
    return 0;
}
