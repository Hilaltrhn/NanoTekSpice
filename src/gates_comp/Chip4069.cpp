/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4069.cpp
*/

#include "../../include/gates_comp/Chip4069.hpp"
#include "../../include/Exceptions.hpp"
#include "../../include/elementary_comp/NotGate.hpp"
#include <memory>

namespace nts
{
    Chip4069::Chip4069()
    {
        _notGate1 = std::make_unique<NotGate>();
        _notGate2 = std::make_unique<NotGate>();
        _notGate3 = std::make_unique<NotGate>();
        _notGate4 = std::make_unique<NotGate>();
        _notGate5 = std::make_unique<NotGate>();
        _notGate6 = std::make_unique<NotGate>();
    }

    void Chip4069::simulate(std::size_t tick)
    {
        _notGate1->simulate(tick);
        _notGate2->simulate(tick);
        _notGate3->simulate(tick);
        _notGate4->simulate(tick);
        _notGate5->simulate(tick);
        _notGate6->simulate(tick);
    }

    nts::Tristate Chip4069::compute(std::size_t pin)
    {
        if (pin == 7 || pin == 14)
            return Undefined;

        switch (pin) {
            case 2:  return _notGate1->compute(2);
            case 4:  return _notGate2->compute(2);
            case 6:  return _notGate3->compute(2);
            case 8:  return _notGate4->compute(2);
            case 10: return _notGate5->compute(2);
            case 12: return _notGate6->compute(2);
            default:
                throw NtsException("Chip4069: cannot compute input pin " + std::to_string(pin));
        }
    }

    void Chip4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 7 || pin == 14)
            return;

        switch (pin) {
            case 1:  _notGate1->setLink(1, other, otherPin); break;
            case 3:  _notGate2->setLink(1, other, otherPin); break;
            case 5:  _notGate3->setLink(1, other, otherPin); break;
            case 9:  _notGate4->setLink(1, other, otherPin); break;
            case 11: _notGate5->setLink(1, other, otherPin); break;
            case 13: _notGate6->setLink(1, other, otherPin); break;

            case 2:  _notGate1->setLink(2, other, otherPin); break;
            case 4:  _notGate2->setLink(2, other, otherPin); break;
            case 6:  _notGate3->setLink(2, other, otherPin); break;
            case 8:  _notGate4->setLink(2, other, otherPin); break;
            case 10: _notGate5->setLink(2, other, otherPin); break;
            case 12: _notGate6->setLink(2, other, otherPin); break;

            default:
                throw NtsException("Chip4069: invalid pin " + std::to_string(pin));
        }
    }
}