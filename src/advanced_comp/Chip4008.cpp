/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4008.cpp
*/

#include "../../include/advanced_comp/Chip4008.hpp"
#include "../../include/Exceptions.hpp"

namespace nts
{
    Chip4008::Chip4008()
        : _cin(nullptr), _cinPin(0)
    {
        for (int i = 0; i < 4; i++) {
            _a[i] = nullptr; _aPin[i] = 0;
            _b[i] = nullptr; _bPin[i] = 0;
        }
    }

    void Chip4008::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate Chip4008::compute(std::size_t pin)
    {
        nts::Tristate a[4], b[4];
        for (int i = 0; i < 4; i++) {
            a[i] = (_a[i]) ? _a[i]->compute(_aPin[i]) : Undefined;
            b[i] = (_b[i]) ? _b[i]->compute(_bPin[i]) : Undefined;
        }
        nts::Tristate cin = (_cin) ? _cin->compute(_cinPin) : False;
        for (int i = 0; i < 4; i++) {
            if (a[i] == Undefined || b[i] == Undefined)
                return Undefined;
        }
        if (cin == Undefined)
            return Undefined;

        int carry = (cin == True) ? 1 : 0;
        int sum[4];
        for (int i = 0; i < 4; i++) {
            int ai = (a[i] == True) ? 1 : 0;
            int bi = (b[i] == True) ? 1 : 0;
            int s = ai + bi + carry;
            sum[i] = s & 1;
            carry = (s >> 1) & 1;
        }

        switch (pin) {
            case 10: return sum[0] ? True : False;
            case 11: return sum[1] ? True : False;
            case 12: return sum[2] ? True : False;
            case 13: return sum[3] ? True : False;
            case 14: return carry  ? True : False;
            default:
                throw NtsException("Chip4008: invalid output pin " + std::to_string(pin));
        }
    }

    void Chip4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        switch (pin) {
            case 7:  _a[0] = &other; _aPin[0] = otherPin; break;
            case 5:  _a[1] = &other; _aPin[1] = otherPin; break;
            case 3:  _a[2] = &other; _aPin[2] = otherPin; break;
            case 1:  _a[3] = &other; _aPin[3] = otherPin; break;
            case 6:  _b[0] = &other; _bPin[0] = otherPin; break;
            case 4:  _b[1] = &other; _bPin[1] = otherPin; break;
            case 2:  _b[2] = &other; _bPin[2] = otherPin; break;
            case 15: _b[3] = &other; _bPin[3] = otherPin; break;
            case 9:  _cin = &other; _cinPin = otherPin;   break;
            case 10: case 11: case 12: case 13: case 14: break;
            case 8: case 16: break;
            default:
                throw NtsException("Chip4008: invalid pin " + std::to_string(pin));
        }
    }
}
