#include "produto.h"
#include "excecoes.h"
// #include <stdexcept> 

// Construtor modificado
Produto::Produto(int codigo, const std::string& nome, double preco, Categoria categoria, int estoque)
    : codigo(codigo), nome(nome), preco(preco), categoria(categoria), estoque(estoque) {
    
    // --- TRATAMENTO PARA VALORES NEGATIVOS ---
    // Adicionamos esta verificação no corpo do construtor.
    if (preco < 0 || estoque < 0) {
        throw std::invalid_argument("Erro de validacao: Preco e estoque nao podem ser negativos.");
    }
    // Se os valores forem válidos, a construção do objeto continua normalmente.
}

// Getters
int Produto::getCodigo() const {
    return codigo;
}

std::string Produto::getNome() const {
    return nome;
}

double Produto::getPreco() const {
    return preco;
}

int Produto::getEstoque() const {
    return estoque;
}

Categoria Produto::getCategoria() const {
    return categoria;
}

std::string Produto::categoriaToString() const {
    switch(categoria) {
        case Categoria::ALIMENTO:   return "Alimento";
        case Categoria::BEBIDA:     return "Bebida";
        case Categoria::ELETRONICO: return "Eletronico";
        case Categoria::VESTUARIO:  return "Vestuario";
        case Categoria::LIVRO:      return "Livro";
        case Categoria::LIMPEZA:    return "Limpeza";
        default:                    return "Desconhecido";
    }
}

// Métodos de manipulação de estoque
void Produto::removerEstoque(int quantidade) {
    if (quantidade > estoque) {
        throw EstoqueInsuficienteException(this->nome, quantidade, this->estoque);
    }
    estoque -= quantidade;
}

// SOBRECARGA DE OPERADOR (adição de estoque)
Produto& Produto::operator+=(int quantidade) {
    if (quantidade > 0) {
        this->estoque += quantidade;
    }
    return *this;
}

bool Produto::operator==(const Produto& outro) const {
    return codigo == outro.codigo;
}

// SOBRECARGA DE OPERADOR (impressão via friend function)
std::ostream& operator<<(std::ostream& os, const Produto& p) {
    os << "Produto [Codigo: " << p.codigo << " | Nome: " << p.nome 
       << " | Preco: R$ " << p.preco << " | Estoque: " << p.estoque 
       << " | Categoria: " << p.categoriaToString() << "]";
    return os;
}