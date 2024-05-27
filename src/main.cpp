/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** main
*/

#include "Plazza.hpp"
#include "Input.hpp"
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

    int pid = fork();

    if (pid == 0) {
        while(kitchen.loop() == 0);
    } else {
        Plazza::InputParser parser = Plazza::InputParser();
        while (1) {
            try {
                parser.parseLine();
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    return 0;
}
