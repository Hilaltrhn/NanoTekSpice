/*
** EPITECH PROJECT, 2025
** G-OOP-400-NCE-4-1-tekspice-16
** File description:
** main.cpp
*/

#include <iostream>
#include <string>
#include <csignal>
#include "../include/Circuit.hpp"
#include "../include/Parser.hpp"

bool g_running = true;

void handleSigint(int)
{
    g_running = false;
}

void run_terminal(nts::Circuit &circuit)
{
    std::string line;

    while (true) {
        std::cout << "> " << std::flush;
        if (!std::getline(std::cin, line))
            break;
        if (line.empty())
            continue;
        if (line == "exit") {
            break;
        } else if (line == "display") {
            circuit.display();
        } else if (line == "simulate") {
            circuit.simulate();
        } else if (line == "loop") {
            g_running = true;
            signal(SIGINT, handleSigint);
            while (g_running) {
                circuit.simulate();
                circuit.display();
            }
            signal(SIGINT, SIG_DFL);

        } else if (line.find('=') != std::string::npos) {
            std::string name  = line.substr(0, line.find('='));
            std::string value = line.substr(line.find('=') + 1);
            circuit.setValue(name, value);

        } else {
            std::cerr << "Unknown command: " << line << std::endl;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <circuit.nts>" << std::endl;
        return 84;
    }
    try {
        nts::Parser parser(argv[1]);
        auto circuit = parser.parse();
        run_terminal(*circuit);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
