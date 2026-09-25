/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** True.hpp
*/

#ifndef TRUE_HPP
#define TRUE_HPP

#include "../IComponent.hpp"

namespace nts
{
    class TrueComp : public IComponent
    {public:
        TrueComp();
        ~TrueComp() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void setValue(nts::Tristate value);
    };
}

#endif
