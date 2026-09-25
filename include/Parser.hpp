/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP
    #define PARSER_HPP

    #include <string>
    #include <memory>
    #include "Circuit.hpp"
    #include "IComponent.hpp"

namespace nts {
    class Parser {
        private:
            std::string _filename;
            std::unique_ptr<Circuit> _circuit;
        public:
            Parser(const std::string &filename);
            ~Parser() {};

            std::string trim(const std::string &str);
            bool isComment(const std::string &line);
            bool isEmpty(const std::string &line);
            void parseChipsets(std::ifstream &file);
            void parseLinks(std::ifstream &file);
            std::unique_ptr<Circuit> parse();
            std::string removeComment(const std::string &line);
    };
}

#endif
