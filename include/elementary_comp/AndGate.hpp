/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** AndGate.hpp
*/

#ifndef ANDGATE_HPP
#define ANDGATE_HPP

#include "../IComponent.hpp"

namespace nts
{
    class AndGate : public IComponent
    {
    public:
        AndGate();
        ~AndGate() = default;
        virtual void simulate(std::size_t tick) override;
        virtual nts::Tristate compute(std::size_t pin) override;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        nts::IComponent *_inputA;
        std::size_t _inputAPin;
        nts::IComponent *_inputB;
        std::size_t _inputBPin;

    };
}

#endif