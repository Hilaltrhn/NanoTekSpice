/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4081.cpp
*/

#include "../../include/gates_comp/Chip4081.hpp"
#include "../../include/Exceptions.hpp"
#include "../../include/elementary_comp/AndGate.hpp"
#include <memory>

namespace nts
{
    Chip4081::Chip4081()
    {
        _andGate1 = std::make_unique<AndGate>();
        _andGate2 = std::make_unique<AndGate>();
        _andGate3 = std::make_unique<AndGate>();
        _andGate4 = std::make_unique<AndGate>();
    }

    void Chip4081::simulate(std::size_t tick)
    {
        _andGate1->simulate(tick);
        _andGate2->simulate(tick);
        _andGate3->simulate(tick);
        _andGate4->simulate(tick);
    }

    nts::Tristate Chip4081::compute(std::size_t pin)
    {
        if (pin == 7 || pin == 14)
            return Undefined;
        switch(pin)
        {
            case 3: return _andGate1->compute(3);
            case 4: return _andGate2->compute(3);
            case 10: return _andGate3->compute(3);
            case 11: return _andGate4->compute(3);
            default:
                throw NtsException("Chip4081: cannot compute input pin " + std::to_string(pin));
        }
    }

    void Chip4081::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 7 || pin == 14)
            return;
        switch (pin) {
            case 1: _andGate1->setLink(1, other, otherPin); break;
            case 2: _andGate1->setLink(2, other, otherPin); break;
            case 3: _andGate1->setLink(3, other, otherPin); break;

            case 5: _andGate2->setLink(1, other, otherPin); break;
            case 6: _andGate2->setLink(2, other, otherPin); break;
            case 4: _andGate2->setLink(3, other, otherPin); break;

            case 8: _andGate3->setLink(1, other, otherPin); break;
            case 9: _andGate3->setLink(2, other, otherPin); break;
            case 10: _andGate3->setLink(3, other, otherPin); break;

            case 12: _andGate4->setLink(1, other, otherPin); break;
            case 13: _andGate4->setLink(2, other, otherPin); break;
            case 11: _andGate4->setLink(3, other, otherPin); break;

            default:
                throw NtsException("Chip4081: invalid pin " + std::to_string(pin));
        }
    }
}