/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4030.cpp
*/

#include "../../include/gates_comp/Chip4030.hpp"
#include "../../include/Exceptions.hpp"
#include "../../include/elementary_comp/XorGate.hpp"
#include <memory>

namespace nts
{
    Chip4030::Chip4030()
    {
        _xorGate1 = std::make_unique<XorGate>();
        _xorGate2 = std::make_unique<XorGate>();
        _xorGate3 = std::make_unique<XorGate>();
        _xorGate4 = std::make_unique<XorGate>();
    }

    void Chip4030::simulate(std::size_t tick)
    {
        _xorGate1->simulate(tick);
        _xorGate2->simulate(tick);
        _xorGate3->simulate(tick);
        _xorGate4->simulate(tick);
    }

    nts::Tristate Chip4030::compute(std::size_t pin)
    {
        if (pin == 7 || pin == 14)
            return Undefined;
        switch(pin)
        {
            case 3: return _xorGate1->compute(3);
            case 4: return _xorGate2->compute(3);
            case 10: return _xorGate3->compute(3);
            case 11: return _xorGate4->compute(3);
            default:
                throw NtsException("Chip4030: cannot compute input pin " + std::to_string(pin));
        }
    }

    void Chip4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 7 || pin == 14)
            return;
        switch (pin) {
            case 1: _xorGate1->setLink(1, other, otherPin); break;
            case 2: _xorGate1->setLink(2, other, otherPin); break;
            case 3: _xorGate1->setLink(3, other, otherPin); break;

            case 5: _xorGate2->setLink(1, other, otherPin); break;
            case 6: _xorGate2->setLink(2, other, otherPin); break;
            case 4: _xorGate2->setLink(3, other, otherPin); break;

            case 8: _xorGate3->setLink(1, other, otherPin); break;
            case 9: _xorGate3->setLink(2, other, otherPin); break;
            case 10: _xorGate3->setLink(3, other, otherPin); break;

            case 12: _xorGate4->setLink(1, other, otherPin); break;
            case 13: _xorGate4->setLink(2, other, otherPin); break;
            case 11: _xorGate4->setLink(3, other, otherPin); break;

            default:
                throw NtsException("Chip4030: invalid pin " + std::to_string(pin));
        }
    }
}