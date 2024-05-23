/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Wrap class of socket Unix in c
*/

#pragma once

#include <sys/socket.h>
#include <sys/un.h>
#include <vector>
#include <string>

namespace SocketU {
    class Server;
    class Client;
};

class SocketU::Server {

    public:

        /**
         * @brief Construct a new Server object.
         *
         */
        Server();

        /**
         * @brief Destroy the Server object.
         *
         */
        ~Server();

        /**
         * @brief Listen for incoming connections
         *
         * @param maxClient The maximum number of clients, default is 5
         */
        void listen(int maxClient = 5);

        /**
         * @brief Accept a connection
         *
         */
        void accept();

        /**
         * @brief Select the write and read file descriptors
         *
         */
        void selectWriteRead();

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
         * @brief Receive a message from a client
         *
         * @param fd_dest The file descriptor of the client
         * @return std::string
         */
        std::string receive(int fd_dest);

        /**
         * @brief Send a message to a client
         *
         * @param message The message to send
         * @param fd_dest The file descriptor of the client
         */
        void send(std::string message, int fd_dest);

        // getters

        /**
         * @brief Get the Socket of the server.
         *
         * @return int
         */
        int getSocket();

        /**
         * @brief Get the clients fds of the server.
         *
         * @return std::vector<int>
         */
        std::vector<int> getClients();

        /**
         * @brief Get the read file descriptor of the server.
         *
         * @return fd_set
         */
        fd_set& getReadfds();

        /**
         * @brief Get the write file descriptor of the server.
         *
         * @return fd_set
         */
        fd_set& getWritefds();

        fd_set              _readfds;
        fd_set              _writefds;

    private:
        int                 _socket;
        std::vector<int>    _clients;
};
