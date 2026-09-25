/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4040.cpp
*/

#include "../../include/advanced_comp/Chip4040.hpp"
#include "../../include/Exceptions.hpp"


namespace nts
{
    Chip4040::Chip4040()
        : _clock(nullptr), _clockPin(0), _reset(nullptr), _resetPin(0), _counter(0), _lastClock(Undefined)
    {
    }

    void Chip4040::simulate(std::size_t tick)
    {
        (void)tick;

        nts::Tristate reset = Undefined;
        if (_reset != nullptr)
            reset = _reset->compute(_resetPin);
        if (reset == True) {
            _counter = 0;
            _lastClock = Undefined;
            return;
        }
        nts::Tristate clock = Undefined;
        if (_clock != nullptr)
            clock = _clock->compute(_clockPin);
        if (_lastClock == True && clock == False) {
            _counter++;
            if (_counter > 4095)
                _counter = 0;
        }
        _lastClock = clock;
    }

    nts::Tristate Chip4040::compute(std::size_t pin)
    {
        if (pin == 8 || pin == 16)
            return Undefined;

        if (pin == 9) {
            if (_counter & (1 << 0))
                return True;
            return False;
        }
        if (pin == 7) {
            if (_counter & (1 << 1))
                return True;
            return False;
        }
        if (pin == 6) {
            if (_counter & (1 << 2))
                return True;
            return False;
        }
        if (pin == 5) {
            if (_counter & (1 << 3))
                return True;
            return False;
        }
        if (pin == 3) {
            if (_counter & (1 << 4))
                return True;
            return False;
        }
        if (pin == 2) {
            if (_counter & (1 << 5))
                return True;
            return False;
        }
        if (pin == 4) {
            if (_counter & (1 << 6))
                return True;
            return False;
        }
        if (pin == 13) {
            if (_counter & (1 << 7))
                return True;
            return False;
        }
        if (pin == 12) {
            if (_counter & (1 << 8))
                return True;
            return False;
        }
        if (pin == 14) {
            if (_counter & (1 << 9))
                return True;
            return False;
        }
        if (pin == 15) {
            if (_counter & (1 << 10))
                return True;
            return False;
        }
        if (pin == 1) {
            if (_counter & (1 << 11))
                return True;
            return False;
        }
        throw NtsException("Chip4040: cannot compute input pin " + std::to_string(pin));
    }

    void Chip4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 8 || pin == 16)
            return;
        if (pin == 10) {
            _clock = &other;
            _clockPin = otherPin;
        } else if (pin == 11) {
            _reset = &other;
            _resetPin = otherPin;
        } else {
        }
    }
}
