/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4030.hpp
*/

#ifndef CHIP4030_HPP
#define CHIP4030_HPP

#include "../IComponent.hpp"
#include <memory>

namespace nts
{
    class Chip4030 : public IComponent
    {
    public:
        Chip4030();
        ~Chip4030() = default;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        std::unique_ptr<IComponent> _xorGate1;
        std::unique_ptr<IComponent> _xorGate2;
        std::unique_ptr<IComponent> _xorGate3;
        std::unique_ptr<IComponent> _xorGate4;
    };
}

#endif