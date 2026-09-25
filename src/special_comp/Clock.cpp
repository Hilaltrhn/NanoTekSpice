/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Clock.cpp
*/

#include "../../include/special_comp/Clock.hpp"
#include "../../include/Exceptions.hpp"

namespace nts
{
    Clock::Clock()
        : _value(Undefined), _nextValue(Undefined)
    {
    }

    void Clock::simulate(std::size_t tick)
    {
        (void)tick;
        _value = _nextValue;
        if (_value == Undefined) {
            return;
        }
        if (_value == True)
            _nextValue = False;
        else _nextValue = True;
    }

    nts::Tristate Clock::compute(std::size_t pin)
    {
        if (pin != 1)
            throw NtsException("Clock: invalid pin " + std::to_string(pin));
        return _value;
    }

    void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        (void)pin;
        (void)other;
        (void)otherPin;
    }

    void Clock::setValue(nts::Tristate value)
    {
        _nextValue = value;
    }
}
