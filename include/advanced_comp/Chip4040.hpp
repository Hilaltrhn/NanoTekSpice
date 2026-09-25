/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4040.hpp
*/

#ifndef CHIP4040_HPP
#define CHIP4040_HPP

#include "../IComponent.hpp"

namespace nts
{
    class Chip4040 : public IComponent
    {
    public:
        Chip4040();
        ~Chip4040() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        nts::IComponent *_clock;
        std::size_t _clockPin;
        nts::IComponent *_reset;
        std::size_t _resetPin;
        unsigned int _counter;
        nts::Tristate _lastClock;
    };
}

#endif