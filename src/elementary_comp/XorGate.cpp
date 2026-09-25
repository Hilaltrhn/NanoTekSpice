/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** XorGate.cpp
*/

#include "../../include/elementary_comp/XorGate.hpp"
#include "../../include/Exceptions.hpp"

namespace nts
{
    XorGate::XorGate()
        : _inputA(nullptr), _inputAPin(0),
        _inputB(nullptr), _inputBPin(0)
    {
    }

    void XorGate(std::size_t tick)
    {
        (void)tick;
    }

    void nts::XorGate::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate XorGate::compute(std::size_t pin)
    {
        if (pin != 3)
            throw NtsException("XorGate: can only compute output pin 3");
        nts::Tristate a = Undefined;
        nts::Tristate b = Undefined;

        if (_inputA != nullptr)
            a = _inputA->compute(_inputAPin);
        if (_inputB != nullptr)
            b = _inputB->compute(_inputBPin);

        if (a == Undefined || b == Undefined)
            return Undefined;
        if (a != b)
            return True;
        return False;
    }

    void nts::XorGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 1)
        {
            _inputA = &other;
            _inputAPin = otherPin;
        } else if (pin == 2) {
            _inputB = &other;
            _inputBPin = otherPin;
        } else if (pin == 3) {
        } else {
            throw NtsException("XorGate: invalid pin " + std::to_string(pin));
        }
    }
}
