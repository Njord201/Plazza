/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Client
*/

#pragma once

#include <sys/socket.h>
#include <sys/un.h>
#include <vector>
#include <string>
#include <memory>

namespace SocketU {
    /**
     * @brief Client class for Unix socket
     *
     */
    class Client;
};

class SocketU::Client {

    public:

        /**
         * @brief Construct a new Client object.
         *
         */
        Client();

        /**
         * @brief Destroy the Client object.
         *
         */
        ~Client();

        /**
         * @brief Connect the client to the server
         *
         */
        void connect();

        /**
         * @brief Select the write file descriptor
         *
         */
        void selectWrite();

        /**
         * @brief Select the read file descriptor
         *
         */
        void selectRead();

        /**
         * @brief Receive a message from the server
         *
         * @return std::string
         */
        std::string receive();

        /**
         * @brief Send a message to the server
         *
         * @param message
         */
        void send(std::string message);

        /**
         * @brief Get the Socket object.
         *
         * @return int - The socket
         */
        int getSocket();

        fd_set _readfds;
        fd_set _writefds;

    private:
        int     _socket;
};
