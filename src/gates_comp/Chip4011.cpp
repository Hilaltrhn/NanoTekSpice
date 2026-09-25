/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4011.cpp
*/

#include "../../include/gates_comp/Chip4011.hpp"
#include "../../include/Exceptions.hpp"
#include "../../include/elementary_comp/NandGate.hpp"
#include <memory>

namespace nts
{
    Chip4011::Chip4011()
    {
        _nandGate1 = std::make_unique<NandGate>();
        _nandGate2 = std::make_unique<NandGate>();
        _nandGate3 = std::make_unique<NandGate>();
        _nandGate4 = std::make_unique<NandGate>();
    }

    void Chip4011::simulate(std::size_t tick)
    {
        _nandGate1->simulate(tick);
        _nandGate2->simulate(tick);
        _nandGate3->simulate(tick);
        _nandGate4->simulate(tick);
    }

    nts::Tristate Chip4011::compute(std::size_t pin)
    {
        if (pin == 7 || pin == 14)
            return Undefined;
        switch(pin)
        {
            case 3: return _nandGate1->compute(3);
            case 4: return _nandGate2->compute(3);
            case 10: return _nandGate3->compute(3);
            case 11: return _nandGate4->compute(3);
            default:
                throw NtsException("Chip4011: cannot compute input pin " + std::to_string(pin));
        }
    }

    void Chip4011::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 7 || pin == 14)
            return;
        switch (pin) {
            case 1: _nandGate1->setLink(1, other, otherPin); break;
            case 2: _nandGate1->setLink(2, other, otherPin); break;
            case 3: _nandGate1->setLink(3, other, otherPin); break;

            case 5: _nandGate2->setLink(1, other, otherPin); break;
            case 6: _nandGate2->setLink(2, other, otherPin); break;
            case 4: _nandGate2->setLink(3, other, otherPin); break;

            case 8: _nandGate3->setLink(1, other, otherPin); break;
            case 9: _nandGate3->setLink(2, other, otherPin); break;
            case 10: _nandGate3->setLink(3, other, otherPin); break;

            case 12: _nandGate4->setLink(1, other, otherPin); break;
            case 13: _nandGate4->setLink(2, other, otherPin); break;
            case 11: _nandGate4->setLink(3, other, otherPin); break;

            default:
                throw NtsException("Chip4011: invalid pin " + std::to_string(pin));
        }
    }
}
