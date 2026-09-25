/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Chip4008.hpp
*/

#ifndef CHIP4008_HPP
    #define CHIP4008_HPP

    #include "../IComponent.hpp"

namespace nts {
    class Chip4008 : public IComponent {
        public:
            Chip4008();
            ~Chip4008() = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        private:
            nts::IComponent *_a[4];
            std::size_t      _aPin[4];
            nts::IComponent *_b[4];
            std::size_t      _bPin[4];
            nts::IComponent *_cin;
            std::size_t      _cinPin;
    };
}

#endif
