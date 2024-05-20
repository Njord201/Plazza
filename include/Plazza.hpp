/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Plazza
*/

#pragma once

#include <string>

namespace Plazza {

    /**
     * @brief Parser class for Plazza.
     *
     */
    class PlazzaParser;

}

class Plazza::PlazzaParser {
    public:

        /**
         * @brief Construct a new Plazza object.
         *
         * @param argc number of arguments
         * @param argv list of arguments
         */
        PlazzaParser(int argc, char **argv);

        /**
         * @brief Destroy the Plazza object.
         *
         */
        ~PlazzaParser() = default;

        /**
         * @brief Class to handle parsing errors.
         *
         */
        class ParserException;

    private:

        double          _timeMultiplier;
        unsigned int    _nbCooks;
        unsigned int    _time;
};

class Plazza::PlazzaParser::ParserException : public std::exception {
    public:

        /**
         * @brief Construct a new Parser Exception object
         *
         * @param msg
         */
        explicit ParserException(const std::string &msg);

        /**
         * @brief Display the message of error.
         *
         * @return const char* message of error
         */
        const char* what() const noexcept override;

    private:

        std::string _message;
};
