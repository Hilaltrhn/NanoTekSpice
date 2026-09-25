/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4001.hpp
*/

#ifndef CHIP4001_HPP
#define CHIP4001_HPP

#include "../IComponent.hpp"
#include <memory>
#include <map>

namespace nts
{
    class Chip4001 : public IComponent
    {
    public:
        Chip4001();
        ~Chip4001() = default;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        std::unique_ptr<IComponent> _norGate1;
        std::unique_ptr<IComponent> _norGate2;
        std::unique_ptr<IComponent> _norGate3;
        std::unique_ptr<IComponent> _norGate4;
    };
}

#endif