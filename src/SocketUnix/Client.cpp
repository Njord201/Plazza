/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Client
*/

#include "SocketUnix/Client.hpp"
#include "SocketUnix/Rules.hpp"

#include <stdexcept>
#include <iostream>
#include <string.h>
#include <unistd.h>

SocketU::Client::Client()
{
    struct sockaddr_un addr;

    this->_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (this->_socket == -1) {
        throw std::runtime_error("Error: socket creation failed");
    }
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);
}

SocketU::Client::~Client()
{
    close(this->_socket);
}

void SocketU::Client::connect()
{
    struct sockaddr_un addr;

    this->_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (this->_socket == -1) {
        throw std::runtime_error("Error: socket creation failed");
    }
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);
    if (::connect(this->_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        throw std::runtime_error("Error: connect failed");
    }
}

void SocketU::Client::selectWrite()
{
    if (::select(FD_SETSIZE, NULL, &this->_writefds, NULL, NULL) == -1) {
        throw std::runtime_error("Error: select failed");
    }
}

void SocketU::Client::selectRead()
{
    if (::select(FD_SETSIZE, &this->_readfds, NULL, NULL, NULL) == -1) {
        throw std::runtime_error("Error: select failed");
    }
}

std::string SocketU::Client::receive()
{
    std::string data;
    char buffer;
    int len;

    if (FD_ISSET(this->_socket, &this->_readfds) == 0) {
        return "";
    }
    while ((len = read(this->_socket, &buffer, 1)) > 0) {
        data.append(&buffer, 1);
        if (buffer == '\0') {
            break;
        }
    }
    return data;
}

void SocketU::Client::send(std::string message)
{
    if (FD_ISSET(this->_socket, &this->_writefds)) {
        if (write(this->_socket, message.c_str(), message.size() + 1) == -1) {
            perror("write");
            throw std::runtime_error("Error: write failed");
        }
    }
}

int SocketU::Client::getSocket()
{
    return this->_socket;
}
