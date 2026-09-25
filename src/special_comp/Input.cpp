/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Input.cpp
*/

#include "../../include/special_comp/Input.hpp"
#include "../../include/Exceptions.hpp"

namespace nts
{
    Input::Input()
        : _value(Undefined), _nextVal(Undefined)
    {
    }

    void Input::simulate(std::size_t tick)
    {
        (void)tick;
        _value = _nextVal;
    }

    nts::Tristate Input::compute(std::size_t pin)
    {
        if (pin != 1)
            throw NtsException("Input: invalid pin " + std::to_string(pin));
        return _value;
    }

    void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        (void)pin;
        (void)other;
        (void)otherPin;
    }

    void Input::setValue(nts::Tristate value)
    {
        _nextVal= value;
    }
}