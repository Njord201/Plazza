/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** test_client
*/

#include "SocketUnix/Client.hpp"

#include <iostream>

int main()
{
    SocketU::Client client;

    client.connect();

    FD_ZERO(&client._writefds);
    FD_SET(client.getSocket(), &client._writefds);

    client.selectWrite();
    auto wrties = client._writefds;
    if (FD_ISSET(client.getSocket(), &wrties)) {
        std::cout << "Sending: Hello" << std::endl;
        client.send("Hello\0");
    }
    FD_ZERO(&client._readfds);
    FD_SET(client.getSocket(), &client._readfds);
    client.selectRead();
    auto reads = client._readfds;
    if (FD_ISSET(client.getSocket(), &reads)) {
        std::cout << "Received: " << client.receive() << std::endl;
    }
    return 0;
}
