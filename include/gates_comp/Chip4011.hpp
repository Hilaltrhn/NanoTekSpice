/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4011.hpp
*/

#ifndef CHIP4011_HPP
#define CHIP4011_HPP

#include "../IComponent.hpp"
#include <memory>

namespace nts
{
    class Chip4011 : public IComponent
    {
    public:
        Chip4011();
        ~Chip4011() = default;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        std::unique_ptr<IComponent> _nandGate1;
        std::unique_ptr<IComponent> _nandGate2;
        std::unique_ptr<IComponent> _nandGate3;
        std::unique_ptr<IComponent> _nandGate4;
    };
}

#endif