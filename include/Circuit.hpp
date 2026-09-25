/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Circuit.hpp
*/

#ifndef CIRCUIT_HPP
    #define CIRCUIT_HPP

    #include <map>
    #include <memory>
    #include <string>
    #include <vector>
    #include "IComponent.hpp"

namespace nts {
    class Circuit {
        public:
            Circuit():_tick(0){}
            ~Circuit() = default;

            void addComponent(const std::string &name, std::unique_ptr<IComponent>component);
            IComponent &getComponent(const std::string &name) const;
            void simulate();
            std::size_t getTick() const;
            std::vector<std::string> getInputNames() const;
            std::vector<std::string> getOutputNames() const;
            bool hasComponent(const std::string &name) const;
            void link(const std::string &comp1Name, std::size_t pin1, const std::string &comp2Name, std::size_t pin2);
            void display() const;
            void setValue(const std::string &name, const std::string &value);

        private:
            std::size_t _tick;
            std::map<std::string, std::unique_ptr<IComponent>> _components;
            std::vector<std::string> _inputNames;
            std::vector<std::string> _outputNames;
    };
}
#endif
