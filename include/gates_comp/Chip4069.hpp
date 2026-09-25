/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4069.hpp
*/

#include "../IComponent.hpp"
#include <memory>

namespace nts
{
    class Chip4069 : public IComponent
    {
    public:
        Chip4069();
        ~Chip4069() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        std::unique_ptr<IComponent> _notGate1;
        std::unique_ptr<IComponent> _notGate2;
        std::unique_ptr<IComponent> _notGate3;
        std::unique_ptr<IComponent> _notGate4;
        std::unique_ptr<IComponent> _notGate5;
        std::unique_ptr<IComponent> _notGate6;
    };
}