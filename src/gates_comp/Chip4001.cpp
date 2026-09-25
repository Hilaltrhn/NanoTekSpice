/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4001.cpp
*/

#include "../../include/gates_comp/Chip4001.hpp"
#include "../../include/Exceptions.hpp"
#include "../../include/elementary_comp/NorGate.hpp"
#include <memory>

namespace nts
{
    Chip4001::Chip4001()
    {
        _norGate1 = std::make_unique<NorGate>();
        _norGate2 = std::make_unique<NorGate>();
        _norGate3 = std::make_unique<NorGate>();
        _norGate4 = std::make_unique<NorGate>();
    }

    void Chip4001::simulate(std::size_t tick)
    {
        _norGate1->simulate(tick);
        _norGate2->simulate(tick);
        _norGate3->simulate(tick);
        _norGate4->simulate(tick);
    }

    nts::Tristate Chip4001::compute(std::size_t pin)
    {
        static int depth = 0;
        if (depth > 50)
            return False;
        depth++;

        if (pin == 7 || pin == 14) {
            depth--;
            return Undefined;
        }

        if (pin == 7 || pin == 14) {
            depth--;
            return Undefined;
        }

        nts::Tristate result;

        switch(pin)
        {
            case 3: result = _norGate1->compute(3); break;
            case 4: result = _norGate2->compute(3); break;
            case 10: result = _norGate3->compute(3); break;
            case 11: result = _norGate4->compute(3); break;
            default:
                depth--;
                throw NtsException("Chip4001: cannot compute input pin " + std::to_string(pin));
        }
        depth--;
        return result;
    }

    void Chip4001::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 7 || pin == 14)
            return;
        switch (pin) {
            case 1: _norGate1->setLink(1, other, otherPin); break;
            case 2: _norGate1->setLink(2, other, otherPin); break;
            case 3: _norGate1->setLink(3, other, otherPin); break;

            case 5: _norGate2->setLink(1, other, otherPin); break;
            case 6: _norGate2->setLink(2, other, otherPin); break;
            case 4: _norGate2->setLink(3, other, otherPin); break;

            case 8: _norGate3->setLink(1, other, otherPin); break;
            case 9: _norGate3->setLink(2, other, otherPin); break;
            case 10: _norGate3->setLink(3, other, otherPin); break;

            case 12: _norGate4->setLink(1, other, otherPin); break;
            case 13: _norGate4->setLink(2, other, otherPin); break;
            case 11: _norGate4->setLink(3, other, otherPin); break;

            default:
                throw NtsException("Chip4001: invalid pin " + std::to_string(pin));
        }
    }
}
