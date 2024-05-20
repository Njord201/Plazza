/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Plazza
*/

#include "Plazza.hpp"

#include <stdexcept>

using PlazzaParser = Plazza::PlazzaParser;

PlazzaParser::PlazzaParser(int argc, char **argv)
{
    if (argc != 4)
        throw PlazzaParser::ParserException("Error: Invalid number of arguments");

    try {
        _timeMultiplier = std::stod(argv[1]);
        if (_timeMultiplier < 0 || _timeMultiplier > 1)
            throw PlazzaParser::ParserException("Error: Invalid time multiplier, must be between 0 and 1");
    } catch (std::invalid_argument &e) {
        throw PlazzaParser::ParserException("Error: Invalid time multiplier, must be a valid number");
    }
    try {
        if (argv[2][0] == '-')
            throw PlazzaParser::ParserException("Error: Invalid number of cooks, must be a valid positive number");
        _nbCooks = std::stoul(argv[2]);
    } catch (std::invalid_argument &e) {
        throw PlazzaParser::ParserException("Error: Invalid number of cooks, must be a valid number");
    }
    try {
        if (argv[3][0] == '-')
            throw PlazzaParser::ParserException("Error: Invalid time, must be a valid positive number");
        _time = std::stoul(argv[3]);
    } catch (std::invalid_argument &e) {
        throw PlazzaParser::ParserException("Error: Invalid time, must be a valid number");
    } catch (std::out_of_range &e) {
        throw PlazzaParser::ParserException("Error: Invalid time, must be a valid positive number");
    }
}

PlazzaParser::ParserException::ParserException(const std::string &msg) : _message(msg)
{
}

const char *PlazzaParser::ParserException::what() const noexcept
{
    return _message.c_str();
}
