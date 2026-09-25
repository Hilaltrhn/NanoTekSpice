/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Factory.hpp
*/

#ifndef FACTORY_HPP
    #define FACTORY_HPP
    #include <map>
    #include <string>
    #include <memory>
    #include <functional>
    #include "IComponent.hpp"

namespace nts {
    class Factory {
        public:
            Factory(const Factory&) = delete;
            Factory& operator=(const Factory&) = delete;
            static Factory& getInstance();

            std::unique_ptr<IComponent> createComponent(const std::string &type);

        private:
            Factory() {};
    };
}

#endif