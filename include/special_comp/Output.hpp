/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Output.hpp
*/

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "../IComponent.hpp"

namespace nts
{
    class Output : public IComponent
    {public:
        Output();
        ~Output() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        nts::IComponent *_linked;
        std::size_t _linkedPin;
    };
}

#endif