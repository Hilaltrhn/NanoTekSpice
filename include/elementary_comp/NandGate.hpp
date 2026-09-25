/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** NandGate.hpp
*/

#ifndef NANDGATE_HPP
#define NANDGATE_HPP

#include "../IComponent.hpp"
#include <memory>

namespace nts
{
    class NandGate : public IComponent
    {
    public:
        NandGate();
        ~NandGate() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        std::unique_ptr<IComponent> _andGate;
        std::unique_ptr<IComponent> _notGate;
    };
}

#endif