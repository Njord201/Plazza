/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** test_server
*/

#include "SocketUnix/Server.hpp"

#include <iostream>

#include <sys/select.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{
    SocketU::Server server;

    server.listen();
    server.accept();

    FD_ZERO(&server._readfds);
    FD_SET(server.getSocket(), &server._readfds);
    for (int client : server.getClients()) {
        FD_SET(client, &server._readfds);
    }
    server.selectRead();
    if (FD_ISSET(server.getClients()[0], &server._readfds)) {
        std::cout << "Received:" << server.receive(server.getClients()[0]) << std::endl;
    }
    FD_ZERO(&server._writefds);
    FD_SET(server.getSocket(), &server._writefds);
    for (int client : server.getClients()) {
        FD_SET(client, &server._writefds);
    }
    server.selectWrite();
    auto& wrties = server._writefds;
    if (FD_ISSET(server.getClients()[0], &server._writefds)) {
        server.send("Hello", server.getClients()[0]);
        std::cout << "Sending: Hello" << std::endl;
    }
    return 0;
}
