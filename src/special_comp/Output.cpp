/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Output.cpp
*/

#include "../../include/special_comp/Output.hpp"
#include "../../include/Exceptions.hpp"

namespace nts
{
    Output::Output()
        : _linked(nullptr), _linkedPin(0)
    {
    }

    void Output::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate Output::compute(std::size_t pin)
    {
        if (pin != 1)
            throw NtsException("Output: invalid pin " + std::to_string(pin));

        if (_linked == nullptr) {
            return Undefined;
        }
        nts::Tristate result = _linked->compute(_linkedPin);
        return result;
    }

   void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        (void)pin;
        _linked = &other;
        _linkedPin = otherPin;
    }
}