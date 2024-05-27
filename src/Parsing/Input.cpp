/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Input
*/

#include "Input.hpp"

using InputParser = Plazza::InputParser;

static std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

static bool isAlpha(char character)
{
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

static bool isStringAlpha(const std::string &str)
{
    for (const char &c : str)
        if (!isAlpha(c))
            return false;
    return true;
}

static bool isValidSize(const std::string &size)
{
    for (const std::string &s : Plazza::PIZZA_SIZE)
        if (s == size)
            return true;
    return false;
}

static bool isValidNbCook(const std::string &str)
{
    if (str[0] != 'x') {
        std::cerr << "x not found" << std::endl;
        return false;
    }
    std::string str2 = str.substr(1);
    return str2.find_first_not_of("0123456789") == std::string::npos;
}

Plazza::PizzaType InputParser::getPizzaType(const std::string &type)
{
    if (type == "Regina")
        return Plazza::PizzaType::Regina;
    if (type == "Margarita")
        return Plazza::PizzaType::Margarita;
    if (type == "Americana")
        return Plazza::PizzaType::Americana;
    if (type == "Fantasia")
        return Plazza::PizzaType::Fantasia;

    throw ParserException("Invalid type");
    return Plazza::PizzaType::Regina;
}

Plazza::PizzaSize InputParser::getPizzaSize(const std::string &size)
{
    if (size == "S")
        return Plazza::PizzaSize::S;
    if (size == "M")
        return Plazza::PizzaSize::M;
    if (size == "L")
        return Plazza::PizzaSize::L;
    if (size == "XL")
        return Plazza::PizzaSize::XL;
    if (size == "XXL")
        return Plazza::PizzaSize::XXL;

    throw ParserException("Invalid size");
    return Plazza::PizzaSize::S;
}

std::vector<Plazza::APizza> InputParser::parseLine(void)
{
    std::string line;

    std::getline(std::cin, line);
    if (line.empty())
        throw ParserException("Empty line");

    std::vector<std::string> tokens = splitString(line, ' ');
    if (tokens.size() % 3 != 0)
        throw ParserException("Invalid number of arguments");

    std::vector<Plazza::APizza> pizzas;
    for (size_t i = 0; i < tokens.size(); i += 3) {
        if (!isStringAlpha(tokens[i]))
            throw ParserException("Invalid type");
        if (!isValidSize(tokens[i + 1]))
            throw ParserException("Invalid size");
        if (!isValidNbCook(tokens[i + 2]))
            throw ParserException("Invalid number of cooks");

        Plazza::PizzaType type = getPizzaType(tokens[i]);
        Plazza::PizzaSize size = getPizzaSize(tokens[i + 1]);

        try {
            std::string str = tokens[i + 2].substr(1);
            unsigned int cooks = std::stoul(str);
            for (unsigned int j = 0; j < cooks; j++) {
                //TO DO: ADD INGREDIENTS AND COOKING TIME
                Plazza::APizza pizza(type, size, std::vector<Ingredient>(), 1);
                pizzas.push_back(pizza);
            }
        } catch (std::exception &e) {
            throw ParserException("Invalid format for number of cook");
        }
    }
    return pizzas;
}

InputParser::ParserException::ParserException(const std::string &msg) : _message(msg)
{
}

const char *InputParser::ParserException::what() const noexcept
{
    return _message.c_str();
}
