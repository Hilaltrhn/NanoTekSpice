/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** True.cpp
*/

#include "../../include/special_comp/True.hpp"
#include "../../include/Exceptions.hpp"

namespace nts
{
    TrueComp::TrueComp()
    {
    }

    void TrueComp::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate TrueComp::compute(std::size_t pin)
    {
        (void)pin;
        return nts::Tristate::True;
    }

    void TrueComp::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        (void)pin;
        (void)other;
        (void)otherPin;
    }
}