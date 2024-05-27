/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** main
*/

#include "PlazzaParser.hpp"
#include "Input.hpp"
#include "Reception.hpp"

#include <iostream>

int main(int ac, char **av)
{
    try {
        Plazza::PlazzaParser plazza(ac, av);
    } catch (Plazza::PlazzaParser::ParserException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    Plazza::Reception reception;
    reception.run();

    return 0;
}
