/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Logic of wrap class of socket Unix in c
*/

#include "SocketUnix/Server.hpp"
#include "SocketUnix/Rules.hpp"

#include <stdexcept>
#include <iostream>
#include <string.h>
#include <unistd.h>

SocketU::Server::Server()
{
    struct sockaddr_un addr;

    this->_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (this->_socket == -1) {
        throw std::runtime_error("Error: socket creation failed");
    }
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);
    if (bind(this->_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        throw std::runtime_error("Error: bind failed");
    }
}

SocketU::Server::~Server()
{
    close(this->_socket);
    unlink(SOCKET_PATH);
    for (int client : this->_clients) {
        close(client);
    }
}

void SocketU::Server::listen(int maxClient)
{
    if (::listen(this->_socket, maxClient) == -1) {
        throw std::runtime_error("Error: listen failed");
    }
}

void SocketU::Server::accept()
{
    struct sockaddr_un addr;
    socklen_t addr_len = sizeof(addr);
    int client = ::accept(this->_socket, (struct sockaddr *)&addr, &addr_len);
    if (client == -1) {
        throw std::runtime_error("Error: accept failed");
    }
    this->_clients.push_back(client);
}

void SocketU::Server::selectWriteRead()
{
    FD_ZERO(&this->_readfds);
    FD_ZERO(&this->_writefds);
    for (int client : this->_clients) {
        FD_SET(client, &this->_readfds);
    }
    for (int client : this->_clients) {
        FD_SET(client, &this->_writefds);
    }
    if (::select(FD_SETSIZE, &this->_readfds, &this->_writefds, NULL, NULL) == -1) {
        throw std::runtime_error("Error: select failed");
    }
}

void SocketU::Server::selectWrite()
{
    if (::select(FD_SETSIZE, NULL, &this->_writefds, NULL, NULL) == -1) {
        throw std::runtime_error("Error: select failed");
    }
}

void SocketU::Server::selectRead()
{
    if (::select(FD_SETSIZE, &this->_readfds, NULL, NULL, NULL) == -1) {
        throw std::runtime_error("Error: select failed");
    }
}

std::string SocketU::Server::receive(int fd_dest)
{
    std::string data;
    char buffer;
    int len;

    if (FD_ISSET(fd_dest, &this->_readfds) == 0) {
        return "";
    }
    while ((len = read(fd_dest, &buffer, 1)) > 0) {
        data.append(&buffer, 1);
        if (buffer == '\0') {
            break;
        }
    }
    return data;
}

void SocketU::Server::send(std::string message, int fd_dest)
{
    if (FD_ISSET(fd_dest, &this->_writefds) == 0) {
        return;
    }
    if (write(fd_dest, message.c_str(), message.size() + 1) == -1) {
        perror("write");
        throw std::runtime_error("Error: write failed");
    }
}

int SocketU::Server::getSocket()
{
    return this->_socket;
}

std::vector<int> SocketU::Server::getClients()
{
    return this->_clients;
}

fd_set& SocketU::Server::getReadfds()
{
    return this->_readfds;
}

fd_set& SocketU::Server::getWritefds()
{
    return this->_writefds;
}
