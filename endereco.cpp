#include "endereco.h"

Endereco::Endereco(const std::string& r, int n, const std::string& b, const std::string& c)
    : rua(r), numero(n), bairro(b), cidade(c) {}

// SOBRECARGA DE OPERADOR
std::ostream& operator<<(std::ostream& os, const Endereco& e) {
    os << "Rua " << e.rua << ", " << e.numero << " - Bairro: " << e.bairro << ", Cidade: " << e.cidade;
    return os;
}