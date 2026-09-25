/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Input.hpp
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include "../IComponent.hpp"

namespace nts
{
    class Input : public IComponent
    {public:
        Input();
        ~Input() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void setValue(nts::Tristate value);

    private:
        nts::Tristate _value;
        nts::Tristate _nextVal;
    };
}

#endif