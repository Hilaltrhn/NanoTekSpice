/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** NandGate.cpp
*/

#include "../../include/elementary_comp/NandGate.hpp"
#include "../../include/elementary_comp/AndGate.hpp"
#include "../../include/elementary_comp/NotGate.hpp"
#include "../../include/Exceptions.hpp"

namespace nts
{
    NandGate::NandGate()
    {
        _andGate = std::make_unique<AndGate>();
        _notGate = std::make_unique<NotGate>();
        _notGate->setLink(1, *_andGate, 3);
    }

    void NandGate::simulate(std::size_t tick)
    {
        _andGate->simulate(tick);
        _notGate->simulate(tick);
    }

    nts::Tristate NandGate::compute(std::size_t pin)
    {
        if (pin != 3)
            throw NtsException("NandGate: can only compute output pin 3");
        return _notGate->compute(2);
    }

    void NandGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 1 || pin == 2) {
            _andGate->setLink(pin, other, otherPin);
        } else if (pin == 3) {
            _notGate->setLink(2, other, otherPin);
        } else {
            throw NtsException("NandGate: invalid pin " + std::to_string(pin));
        }
    }
}