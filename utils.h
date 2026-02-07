#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <limits>

// FUNÇÃO TEMPLATE: Lê de forma segura qualquer tipo de dado do console.
template <typename T>
T lerEntrada(const std::string& prompt) {
    T valor;
    while (true) {
        std::cout << prompt;
        std::cin >> valor;

        if (std::cin.good()) { // validação de leitura
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpeza do buffer
            return valor;
        }
        std::cout << "Entrada invalida. Por favor, tente novamente." << std::endl;
        std::cin.clear(); // evitar loop
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // evitar loop
    }
}

// Sobrecarga para std::string
inline std::string lerString(const std::string& prompt) {
    std::string valor;
    std::cout << prompt;
    std::getline(std::cin, valor); // lê linha inteira + espaços + \n
    return valor;
}

#endif