#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

// EXCEÇÃO PARA ERROS DE VALIDAÇÃO DE DADOS (ex: CPF/CNPJ inválido)
class ValidacaoException : public std::runtime_error {
public:
    // CONSTRUTOR DE UM CLASSE DE EXCEÇÃO PERSONALIZADA (explicit impede conversões implícitas)
    explicit ValidacaoException(const std::string& message)
        : std::runtime_error("Erro de Validacao: " + message) {}
};

// EXCEÇÃO PARA QUANDO O ESTOQUE DE UM PRODUTO É INSUFICIENTE 
class EstoqueInsuficienteException : public std::runtime_error {
public:
    EstoqueInsuficienteException(const std::string& nomeProduto, int solicitado, int disponivel)
        : std::runtime_error("Estoque Insuficiente para o produto '" + nomeProduto +
                             "'. Solicitado: " + std::to_string(solicitado) +
                             ", Disponivel: " + std::to_string(disponivel)) {} // to_string converte números em string
};

// EXCEÇÃO PARA QUANDO UM ITEM (produto, cliente, etc.) NÃO É ENCONTRADO
class ItemNaoEncontradoException : public std::runtime_error {
public:
    explicit ItemNaoEncontradoException(const std::string& message)
        : std::runtime_error("Erro: " + message) {}
};

#endif