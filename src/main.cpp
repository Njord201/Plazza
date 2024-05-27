/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** main
*/

#include "PlazzaParser.hpp"
#include "Input.hpp"
#include "Reception.hpp"
#include "Kitchen.hpp"

#include <iostream>
#include <unistd.h>

int main(int ac, char **av)
{
    try {
        Plazza::PlazzaParser plazza(ac, av);
    } catch (Plazza::PlazzaParser::ParserException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    Kitchen kitchen(2, 2000, 0);

    Plazza::Reception reception;
    reception.run();

    return 0;
}
