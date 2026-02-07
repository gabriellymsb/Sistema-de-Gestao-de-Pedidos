#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
#include <stdexcept> // BIBLIOTECA DE EXCEÇÃO

enum class Categoria {
    ALIMENTO,
    BEBIDA,
    ELETRONICO,
    VESTUARIO,
    LIVRO,
    LIMPEZA
};

class Produto {
private:
    int codigo;
    std::string nome;
    double preco;
    Categoria categoria;
    int estoque;

public:
    Produto(int codigo, const std::string& nome, double preco, Categoria categoria, int estoque);

    int getCodigo() const;
    std::string getNome() const;
    double getPreco() const;
    int getEstoque() const;
    std::string categoriaToString() const;
    Categoria getCategoria() const; 

    void removerEstoque(int quantidade);

    // SOBRECARGA DE OPERADORES
    Produto& operator+=(int quantidade);
    
    bool operator==(const Produto& outro) const;
    
    // FUNÇÃO FRIEND
    friend std::ostream& operator<<(std::ostream& os, const Produto& p);
};

#endif