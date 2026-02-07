#include "clienteFisico.h"
#include "excecoes.h"
#include <iostream>

ClienteFisico::ClienteFisico(int codigo, const std::string& nome, const Endereco& endereco, const std::string& cpf)
    : Cliente(codigo, nome, endereco) {
    // TRATAMENTO DE EXCEÇÃO: Lança exceção se o CPF for inválido
    if (!validarCPF(cpf)) {
        throw ValidacaoException("CPF invalido: " + cpf);
    }
    this->CPF = cpf;
}

// Implementação do método estático
bool ClienteFisico::validarCPF(const std::string& cpf) {
    // Validação simples (apenas tamanho) para fins de exemplo
    return cpf.length() == 11;
}

void ClienteFisico::imprimir(std::ostream& os) const {
    os << "Cliente Fisico [Codigo: " << codigo << "]\n"
       << "Nome: " << nome << "\n"
       << "CPF: " << CPF << "\n"
       << "Endereco: " << m_endereco; // Usa o operator<< de Endereco
}

double ClienteFisico::getDesconto() const {
    return 0.10; 
}