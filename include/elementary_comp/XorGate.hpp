/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** XorGate.hpp
*/

#ifndef XORGATE_HPP
#define XORGATE_HPP

#include "../IComponent.hpp"

namespace nts
{
    class XorGate : public IComponent
    {
    public:
        XorGate();
        ~XorGate() = default;
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