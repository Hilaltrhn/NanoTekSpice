/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Exceptions.hpp
*/

#ifndef EXCEPTIONS_HPP
    #define EXCEPTIONS_HPP

    #include <iostream>
    #include <exception>
    #include <string>

namespace nts {
    class NtsException : public std::exception
    {
        public:
            NtsException(const std::string &msg) : _msg(msg) {}
            const char *what() const noexcept override
            { return _msg.c_str(); }
        private:
            std::string _msg;
    };

    class ParserException : public NtsException
    {
        public:
            ParserException(const std::string &msg) : NtsException("Parsing error: " + msg) {};
    };

    class FactoryException : public NtsException
    {
        public:
            FactoryException(const std::string &msg) : NtsException("Factory error: " + msg) {};
    };

    class CircuitExeption : public NtsException
    {
        public:
            CircuitExeption(const std::string &msg) : NtsException("Circuit error: " + msg) {};
    };
}

#endif