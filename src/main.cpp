/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** main
*/

#include "PlazzaParser.hpp"
#include "Input.hpp"

#include <iostream>

int main(int ac, char **av)
{
    try {
        Plazza::PlazzaParser plazza(ac, av);
    } catch (Plazza::PlazzaParser::ParserException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    Plazza::InputParser parser = Plazza::InputParser();
    while (1) {
        try {
            parser.parseLine();
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
