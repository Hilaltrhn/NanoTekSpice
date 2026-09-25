/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** NotGate.cpp
*/

#include "../../include/elementary_comp/NotGate.hpp"
#include "../../include/Exceptions.hpp"

namespace nts
{
    NotGate::NotGate()
        : _input(nullptr), _inputPin(0)
    {
    }

    void NotGate(std::size_t tick)
    {
        (void)tick;
    }

    void nts::NotGate::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate NotGate::compute(std::size_t pin)
    {
        if (pin != 2)
            throw NtsException("NotGate: can only compute output pin 2");
        nts::Tristate a = Undefined;

        if (_input != nullptr)
            a = _input->compute(_inputPin);
        if (a == True)
            return False;
        if (a == False)
            return True;
        return Undefined;
    }

    void NotGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 1) {
            _input = &other;
            _inputPin = otherPin;
        } else if (pin == 2) {
        } else {
            throw NtsException("NotGate: invalid pin");
        }
    }
}
