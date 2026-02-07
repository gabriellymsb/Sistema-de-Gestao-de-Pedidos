#include "cliente.h"

// INICIALIZAÇÃO MEMBRO ESTÁTICO (ME)
int Cliente::totalClientes = 0;

Cliente::Cliente(int codigo, const std::string& nome, const Endereco& endereco) 
    : codigo(codigo), nome(nome), m_endereco(endereco) {
    totalClientes++; // INCREMENTA CONTADOR
}

Cliente::~Cliente() {
    totalClientes--; // DECREMENTA CONTADOR 
}

int Cliente::getCodigo() const {
    return codigo;
}

std::string Cliente::getNome() const {
    return nome;
}

// IMPLEMENTAÇÃO ME
int Cliente::getTotalClientes() {
    return totalClientes;
}

// SOBRECARGA DE OPERADOR (implementação da função friend)
// Esta função chama a versão virtual para garantir o comportamento polimórfico correto
std::ostream& operator<<(std::ostream& os, const Cliente& cliente) {
    cliente.imprimir(os);
    return os;
}