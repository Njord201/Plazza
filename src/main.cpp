/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** main
*/

#include "Input.hpp"

#include <iostream>

int main(int ac, char **av)
{
    Plazza::InputParser parser = Plazza::InputParser();
    while (1) {
        try {
            parser.parseLine();
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    (void) ac;
    (void) av;

    return 0;
}
