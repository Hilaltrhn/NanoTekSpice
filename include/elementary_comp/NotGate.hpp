/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** NotGate.hpp
*/

#ifndef NOTGATE_HPP
#define NOTGATE_HPP

#include "../IComponent.hpp"

namespace nts
{
    class NotGate : public IComponent
    {
    public:
        NotGate();
        ~NotGate() = default;
        virtual void simulate(std::size_t tick) override;
        virtual nts::Tristate compute(std::size_t pin) override;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        nts::IComponent *_input;
        std::size_t _inputPin;
    };
}

#endif