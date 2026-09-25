/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** AComponent.hpp
*/

#ifndef ACOMPONENT_HPP
    #define ACOMPONENT_HPP
    #include "IComponent.hpp"

class AComponent : public nts::IComponent {
    public:
        int compute() {
            return 0;
        };
        std::string simulate();
        std::size_t pin(std::string getLink);
};

#endif