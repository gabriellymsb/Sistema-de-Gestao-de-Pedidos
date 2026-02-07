#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "excecoes.h"

// CLASSE TEMPLATE: Gerencia uma coleção de qualquer tipo T.
template <typename T>
class Gerenciador {
private:
    std::vector<T> elementos;
    int proximoCodigo = 1; // Para gerar códigos automaticamente.

public:
    // essa função aceita zero ou mais tipos e Args... representa um pacote de tipos.
    // ex: Args = <int, const char*, double> 
    template<typename... Args>

    // Adiciona um elemento construído no local (emplace_back) e preserva exatamente como o arg foi passado (forwarding).
    void adicionar(Args&&... args) {
        elementos.emplace_back(std::forward<Args>(args)...);
    }
    
    // Busca um elemento pelo código (dentro do conteiner elementos). Lança exceção se não encontrar.
    T& buscarPorCodigo(int codigo) {
        auto it = std::find_if(elementos.begin(), elementos.end(), // estrutura lambda { [caputura] (parâmetros) retorno_tipo {corpo} }
            [codigo](const T& el) { return el.getCodigo() == codigo; }); // captura = [codigo] ; parâmetro = (const T& el) ; retorno = bool ; corpo = comparação

        if (it == elementos.end()) {
            throw ItemNaoEncontradoException("Item com codigo " + std::to_string(codigo) + " nao encontrado.");
        }
        return *it; // objeto apontado - retorno é uma referência (T&)
    }

    // Remove um elemento pelo código (dentro do conteiner elementos).
    void removerPorCodigo(int codigo) {
        auto it = std::find_if(elementos.begin(), elementos.end(),
            [codigo](const T& el) { return el.getCodigo() == codigo; });

        if (it != elementos.end()) {
            elementos.erase(it);
        } else {
            throw ItemNaoEncontradoException("Nao foi possivel remover. Item com codigo " + std::to_string(codigo) + " nao encontrado.");
        }
    }
    
    // Lista todos os elementos usando o operator<< sobrecarregado
    void listarTodos() const {
        if (elementos.empty()) {
            std::cout << "Nenhum item cadastrado." << std::endl;
            return;
        }
        for (const auto& el : elementos) {
            std::cout << el << std::endl;
        }
    }
    
    // Retorna o próximo código disponível
    int getProximoCodigo() {
        return proximoCodigo++;
    }

    const std::vector<T>& getTodos() const {
        return elementos;
    }

    std::vector<T>& getTodos() {
        return elementos;
    }
};

#endif