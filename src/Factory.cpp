/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Factory.cpp
*/

#include "../include/Factory.hpp"
#include "../include/Exceptions.hpp"
#include "../include/IComponent.hpp"
#include "../include/special_comp/Input.hpp"
#include "../include/special_comp/Output.hpp"
#include "../include/special_comp/Clock.hpp"
#include "../include/special_comp/True.hpp"
#include "../include/special_comp/False.hpp"
#include "../include/elementary_comp/AndGate.hpp"
#include "../include/elementary_comp/OrGate.hpp"
#include "../include/elementary_comp/XorGate.hpp"
#include "../include/elementary_comp/NotGate.hpp"
#include "../include/gates_comp/Chip4001.hpp"
#include "../include/gates_comp/Chip4011.hpp"
#include "../include/gates_comp/Chip4030.hpp"
#include "../include/gates_comp/Chip4069.hpp"
#include "../include/gates_comp/Chip4071.hpp"
#include "../include/gates_comp/Chip4081.hpp"
#include "../include/advanced_comp/Chip4040.hpp"
#include "../include/advanced_comp/Chip4008.hpp"

namespace nts {

    Factory& Factory::getInstance()
    {
        static Factory instance;
        return instance;
    }

std::unique_ptr<IComponent> Factory::createComponent(const std::string &type)
{
    static const std::map<std::string, std::function<std::unique_ptr<IComponent>()>> creators =
    {
        {"input", []() { return std::make_unique<Input>(); }},
        {"output", []() { return std::make_unique<Output>(); }},
        {"clock", []() { return std::make_unique<Clock>(); }},
        {"true", []() { return std::make_unique<TrueComp>(); }},
        {"false", []() { return std::make_unique<FalseComp>(); }},

        {"and", []() { return std::make_unique<AndGate>(); }},
        {"or", []() { return std::make_unique<OrGate>(); }},
        {"xor", []() { return std::make_unique<XorGate>(); }},
        {"not", []() { return std::make_unique<NotGate>(); }},

        {"4001", []() { return std::make_unique<Chip4001>(); }},
        {"4011", []() { return std::make_unique<Chip4011>(); }},
        {"4030", []() { return std::make_unique<Chip4030>(); }},
        {"4069", []() { return std::make_unique<Chip4069>(); }},
        {"4071", []() { return std::make_unique<Chip4071>(); }},
        {"4081", []() { return std::make_unique<Chip4081>(); }},
        {"4040", []() { return std::make_unique<Chip4040>(); }},
        {"4008", []() { return std::make_unique<Chip4008>(); }}

    };
    auto it = creators.find(type);
    if (it == creators.end())
        throw FactoryException("Unknown component type: " + type);
    return it->second();
    }
}