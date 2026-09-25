/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** False.cpp
*/

#include "../../include/special_comp/False.hpp"
#include "../../include/Exceptions.hpp"

namespace nts
{
    FalseComp::FalseComp()
    {
    }

    void FalseComp::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate FalseComp::compute(std::size_t pin)
    {
        (void)pin;
        return nts::Tristate::False;
    }

    void FalseComp::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        (void)pin;
        (void)other;
        (void)otherPin;
    }
}