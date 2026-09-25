/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Clock.hpp
*/

#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "../IComponent.hpp"

namespace nts
{
    class Clock : public IComponent
    {public:
        Clock();
        ~Clock() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void setValue(nts::Tristate value);

    private:
        nts::Tristate _value;
        nts::Tristate _nextValue;
    };
}

#endif