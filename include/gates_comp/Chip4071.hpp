/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4071.hpp
*/

#ifndef CHIP4071_HPP
#define CHIP4071_HPP

#include "../IComponent.hpp"
#include <memory>

namespace nts
{
    class Chip4071 : public IComponent
    {
    public:
        Chip4071();
        ~Chip4071() = default;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        std::unique_ptr<IComponent> _orGate1;
        std::unique_ptr<IComponent> _orGate2;
        std::unique_ptr<IComponent> _orGate3;
        std::unique_ptr<IComponent> _orGate4;
    };
}

#endif