/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** False.hpp
*/

#ifndef FALSE_HPP
#define FALSE_HPP

#include "../IComponent.hpp"

namespace nts
{
    class FalseComp : public IComponent
    {public:
        FalseComp();
        ~FalseComp() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void setValue(nts::Tristate value);
    };
}

#endif
