#include "clienteJuridico.h"
#include "excecoes.h"
#include <iostream>

ClienteJuridico::ClienteJuridico(int codigo, const std::string& nome, const Endereco& endereco, const std::string& cnpj)
    : Cliente(codigo, nome, endereco) {
    // TRATAMENTO DE EXCEÇÃO: Lança exceção se o CNPJ for inválido
    if (!validarCNPJ(cnpj)) {
        throw ValidacaoException("CNPJ invalido: " + cnpj);
    }
    this->CNPJ = cnpj;
}

bool ClienteJuridico::validarCNPJ(const std::string& cnpj) {
    // Validação simples (apenas tamanho) para fins de exemplo
    return cnpj.length() == 14;
}

void ClienteJuridico::imprimir(std::ostream& os) const {
    os << "Cliente Juridico [Codigo: " << codigo << "]\n"
       << "Nome: " << nome << "\n"
       << "CNPJ: " << CNPJ << "\n"
       << "Endereco: " << m_endereco; // Usa o operator<< de Endereco
}

double ClienteJuridico::getDesconto() const {
    return 0.15;
}