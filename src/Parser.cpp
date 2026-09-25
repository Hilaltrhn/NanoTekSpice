/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Parser.cpp
*/

#include "../include/Parser.hpp"
#include "../include/Factory.hpp"
#include "../include/Exceptions.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

namespace nts {
    Parser::Parser(const std::string &filename)
        : _filename(filename), _circuit(std::make_unique<Circuit>()) {}

    std::string Parser::trim(const std::string &str)
    {
        auto start = str.find_first_not_of(" \t\r\n");
        if (start == std::string::npos) return "";
        auto end = str.find_last_not_of(" \t\r\n");
        return str.substr(start, end - start + 1);
    }

    std::string Parser::removeComment(const std::string &line)
    {
        auto pos = line.find('#');

        if (pos == std::string::npos)
            return line;
        return line.substr(0, pos);
    }

    bool Parser::isComment(const std::string &line)
    {
        std::string trimmed = trim(line);
        return trimmed.empty() || trimmed[0] == '#';
    }

    bool Parser::isEmpty(const std::string &line)
    {
        return trim(line).empty();
    }

    void Parser::parseChipsets(std::ifstream &file)
    {
        std::string line;
        bool hasComponents = false;
        bool foundLinks = false;

        while (std::getline(file, line)) {
            std::string cleaned = trim(removeComment(line));

            if (cleaned.empty())
                continue;

            if (cleaned == ".links:") {
                foundLinks = true;
                break;
            }

            std::istringstream iss(cleaned);
            std::string type, name;
            if (!(iss >> type >> name))
                throw ParserException("Invalid chipset line: " + line);

            auto component = Factory::getInstance().createComponent(type);
            _circuit->addComponent(name, std::move(component));
            hasComponents = true;
        }

        if (!hasComponents)
            throw ParserException("No components found in .chipsets: section");
        if (!foundLinks)
            throw ParserException("Missing .links: section");
    }

    void Parser::parseLinks(std::ifstream &file)
    {
        std::string line;
        while (std::getline(file, line)) {
            if (isComment(line) || isEmpty(line))
                continue;

            std::string cleaned = trim(removeComment(line));
            if (cleaned.empty())
                continue;

            std::istringstream iss(cleaned);
            std::string link1, link2;

            if (!(iss >> link1 >> link2))
                throw ParserException("Invalid link line: " + line);

            auto pos1 = link1.find(':');
            auto pos2 = link2.find(':');

            if (pos1 == std::string::npos || pos2 == std::string::npos)
                throw ParserException("Invalid link format: " + line);

            std::string comp1 = link1.substr(0, pos1);
            std::string comp2 = link2.substr(0, pos2);
            std::size_t pin1 = std::stoul(link1.substr(pos1 + 1));
            std::size_t pin2 = std::stoul(link2.substr(pos2 + 1));

            _circuit->link(comp1, pin1, comp2, pin2);
        }
    }

    std::unique_ptr<Circuit> Parser::parse()
    {
        std::ifstream file(_filename);
        if (!file.is_open())
            throw ParserException("No file found: " + _filename);

        std::string line;
        bool inChipsets = false;

        while (std::getline(file, line)) {
            std::string cleaned = trim(removeComment(line));

            if (cleaned.empty())
                continue;

            if (cleaned == ".chipsets:") {
                inChipsets = true;
                parseChipsets(file);
                parseLinks(file);
                break;
            }
        }

        if (!inChipsets)
            throw ParserException("Missing .chipsets: section");

        return std::move(_circuit);
    }
}
