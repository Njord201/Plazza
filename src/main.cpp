/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** main
*/

#include "Plazza.hpp"

#include <iostream>

int main(int ac, char **av)
{
    try {
        Plazza::PlazzaParser plazza(ac, av);
    } catch (Plazza::PlazzaParser::ParserException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
