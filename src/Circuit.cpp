/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** Circuit.cpp
*/

#include "../include/Circuit.hpp"
#include "../include/Exceptions.hpp"
#include "../include/special_comp/Input.hpp"
#include "../include/special_comp/Clock.hpp"
#include "../include/special_comp/Output.hpp"

namespace nts {
    void Circuit::addComponent(const std::string &name, std::unique_ptr<IComponent>component)
    {
        if (_components.find(name) != _components.end()) {
            throw CircuitExeption("Component already exists: " + name);
        }
        _components[name] = std::move(component);
    }

    IComponent &Circuit::getComponent(const std::string &name) const
    {
        if (_components.find(name) == _components.end()) {
            throw CircuitExeption("No component found: " + name);
        }
        return *(_components.find(name)->second);
    }

    bool Circuit::hasComponent(const std::string &name) const
    {
        return _components.find(name) != _components.end();
    }

    void Circuit::link(const std::string &comp1Name, std::size_t pin1, const std::string &comp2Name, std::size_t pin2)
    {
        IComponent &comp1 = getComponent(comp1Name);
        IComponent &comp2 = getComponent(comp2Name);

        comp1.setLink(pin1, comp2, pin2);
        comp2.setLink(pin2, comp1, pin1);
    }

    void Circuit::simulate()
    {
        _tick++;

        for (auto &pair : _components) {
            pair.second->simulate(_tick);
        }
    }

    static std::string tristateToStr(nts::Tristate value)
    {
        if (value == nts::Tristate::True)
            return "1";
        if (value == nts::Tristate::False)
            return "0";
        return "U";
    }

    void Circuit::display() const
    {
        std::cout << "tick: " << _tick << std::endl;

        std::cout << "input(s):" << std::endl;
        for (auto &[name, component] : _components) {
            if (dynamic_cast<Input*>(component.get()) != nullptr ||
                dynamic_cast<Clock*>(component.get()) != nullptr)
                std::cout << "  " << name << ": " << tristateToStr(component->compute(1)) << std::endl;
        }
        std::cout << "output(s):" << std::endl;
        for (auto &[name, component] : _components) {
            if (dynamic_cast<Output*>(component.get()) != nullptr)
                std::cout << "  " << name << ": " << tristateToStr(component->compute(1)) << std::endl;
        }
    }

    void Circuit::setValue(const std::string &name, const std::string &value)
    {
        Input *input = dynamic_cast<Input*>(&getComponent(name));
        Clock *clock = dynamic_cast<Clock*>(&getComponent(name));

        Tristate tristate;
        if (value == "0")
            tristate = Tristate::False;
        else if (value == "1")
            tristate = Tristate::True;
        else if (value == "U")
            tristate = Tristate::Undefined;
        else
            throw CircuitExeption("Invalid value: " + value);

        if (input)
            input->setValue(tristate);
        else if (clock)
            clock->setValue(tristate);
        else
            throw CircuitExeption(name + " is not an input or clock");
    }

    std::size_t Circuit::getTick() const
    {
        return _tick;
    }

    std::vector<std::string> Circuit::getInputNames() const
    {
        return _inputNames;
    }

    std::vector<std::string> Circuit::getOutputNames() const
    {
        return _outputNames;
    }
}
