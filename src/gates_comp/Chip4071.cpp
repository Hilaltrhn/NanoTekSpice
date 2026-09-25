/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4071.cpp
*/

#include "../../include/gates_comp/Chip4071.hpp"
#include "../../include/Exceptions.hpp"
#include "../../include/elementary_comp/OrGate.hpp"
#include <memory>

namespace nts
{
    Chip4071::Chip4071()
    {
        _orGate1 = std::make_unique<OrGate>();
        _orGate2 = std::make_unique<OrGate>();
        _orGate3 = std::make_unique<OrGate>();
        _orGate4 = std::make_unique<OrGate>();
    }

    void Chip4071::simulate(std::size_t tick)
    {
        _orGate1->simulate(tick);
        _orGate2->simulate(tick);
        _orGate3->simulate(tick);
        _orGate4->simulate(tick);
    }

    nts::Tristate Chip4071::compute(std::size_t pin)
    {
        if (pin == 7 || pin == 14)
            return Undefined;
        switch(pin)
        {
            case 3: return _orGate1->compute(3);
            case 4: return _orGate2->compute(3);
            case 10: return _orGate3->compute(3);
            case 11: return _orGate4->compute(3);
            default:
                throw NtsException("Chip4071: cannot compute input pin " + std::to_string(pin));
        }
    }

    void Chip4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 7 || pin == 14)
            return;
        switch (pin) {
            case 1: _orGate1->setLink(1, other, otherPin); break;
            case 2: _orGate1->setLink(2, other, otherPin); break;
            case 3: _orGate1->setLink(3, other, otherPin); break;

            case 5: _orGate2->setLink(1, other, otherPin); break;
            case 6: _orGate2->setLink(2, other, otherPin); break;
            case 4: _orGate2->setLink(3, other, otherPin); break;

            case 8: _orGate3->setLink(1, other, otherPin); break;
            case 9: _orGate3->setLink(2, other, otherPin); break;
            case 10: _orGate3->setLink(3, other, otherPin); break;

            case 12: _orGate4->setLink(1, other, otherPin); break;
            case 13: _orGate4->setLink(2, other, otherPin); break;
            case 11: _orGate4->setLink(3, other, otherPin); break;

            default:
                throw NtsException("Chip4071: invalid pin " + std::to_string(pin));
        }
    }
}
