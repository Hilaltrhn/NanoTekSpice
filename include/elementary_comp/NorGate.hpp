/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** NorGate.hpp
*/

#ifndef NORGATE_HPP
#define NORGATE_HPP

#include "../IComponent.hpp"
#include <map>

namespace nts
{
    class NorGate : public IComponent
    {
    public:
        NorGate() = default;
        ~NorGate() = default;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
    struct Link {
        nts::IComponent *component;
        std::size_t pin;
    };

    std::map<std::size_t, Link> _links;
    bool _computing = false;
    nts::Tristate _lastOutput = Undefined;

    };
}

#endif