/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** NorGate.cpp
*/

#include "../../include/elementary_comp/NorGate.hpp"
#include "../../include/elementary_comp/OrGate.hpp"
#include "../../include/elementary_comp/NotGate.hpp"
#include "../../include/Exceptions.hpp"

namespace nts
{
    void NorGate::simulate(std::size_t tick)
    {
        (void)tick;
        _computing = false;
    }

    nts::Tristate NorGate::compute(std::size_t pin)
    {
        if (pin != 3)
            throw NtsException("NorGate: can only compute pin 3");
        if (_computing)
            return _lastOutput;
        _computing = true;

        nts::Tristate a = Undefined;
        nts::Tristate b = Undefined;

        if (_links.count(1))
            a = _links[1].component->compute(_links[1].pin);
        if (_links.count(2))
            b = _links[2].component->compute(_links[2].pin);
        _computing = false;

        if (a == True || b == True)
            return False;
        if (a == Undefined || b == Undefined)
            return Undefined;
        return True;
    }

    void NorGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin < 1 || pin > 3)
            throw NtsException("NorGate: invalid pin");
        _links[pin] = { &other, otherPin };
    }
}
