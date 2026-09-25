/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4081.hpp
*/

#ifndef CHIP4081_HPP
#define CHIP4081_HPP

#include "../IComponent.hpp"
#include <memory>

namespace nts
{
    class Chip4081 : public IComponent
    {
    public:
        Chip4081();
        ~Chip4081() = default;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        std::unique_ptr<IComponent> _andGate1;
        std::unique_ptr<IComponent> _andGate2;
        std::unique_ptr<IComponent> _andGate3;
        std::unique_ptr<IComponent> _andGate4;
    };
}

#endif