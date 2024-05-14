/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Input
*/

#pragma once

#include <string>
#include <vector>
#include <exception>

#include "Pizza.hpp"

namespace Plazza {

    /**
     * @brief InputParser class for the Plazza project.
     *
     */
    class InputParser;

    const std::string PIZZA_TYPE[] = {
        "Regina",
        "Margarita",
        "Americana",
        "Fantasia"
    };

    const std::string PIZZA_SIZE[] = {
        "S",
        "M",
        "L",
        "XL",
        "XXL"
    };

}

class Plazza::InputParser {
    public:

        /**
         * @brief Construct a new InputParser object.
         *
         */
        InputParser() = default;

        /**
         * @brief Destroy the InputParser object.
         *
         */
        ~InputParser() = default;

        /**
         * @brief Parse a line of input.
         *
         * @param line The line to parse.
         * @return Plazza::Pizza The pizza parsed.
         */
        std::vector<Plazza::Pizza> parseLine(void);

        /**
         * @brief Class to handle parsing errors.
         *
         */
        class ParserException;

    private:

        /**
         * @brief Get the Pizza Type object from a string.
         *
         * @param type String to convert.
         * @return Plazza::PizzaType
         */
        Plazza::PizzaType getPizzaType(const std::string &type);

        /**
         * @brief Get the Pizza Size object from a string.
         *
         * @param size String to convert.
         * @return Plazza::PizzaSize
         */
        Plazza::PizzaSize getPizzaSize(const std::string &size);

        std::vector <Plazza::PizzaType>   _type;
        std::vector <Plazza::PizzaSize>   _size;
};

class Plazza::InputParser::ParserException : public std::exception {
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
