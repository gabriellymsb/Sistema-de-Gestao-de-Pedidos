#include "pedido.h"
#include "excecoes.h"
#include <stdexcept>

Pedido::Pedido(int codigo, Cliente* cliente) : codigo(codigo), cliente_p(cliente), valorFinal(0.0) {}

int Pedido::getCodigo() const { return codigo; }

void Pedido::adicionarItem(Produto& produto, int quantidade) {
    // A exceção EstoqueInsuficienteException será lançada aqui se não houver estoque
    // e será capturada na função que chamou (em main.cpp).
    produto.removerEstoque(quantidade); 

    for (auto& item_existente : itens) {
        if (item_existente.getProduto().getCodigo() == produto.getCodigo()) {
            item_existente.adicionarQuantidade(quantidade);
            calcularValorFinal();
            return;
        }
    }
    itens.emplace_back(produto, quantidade);
    calcularValorFinal();
}

void Pedido::calcularValorFinal() {
    double subtotal = 0.0;
    for (const auto& item : itens) {
        subtotal += item.getValorTotal();
    }
    if (cliente_p) {
        valorFinal = subtotal * (1.0 - cliente_p->getDesconto());
    } else {
        valorFinal = subtotal;
    }
}

// SOBRECARGA DE OPERADOR com tratamento de exceção
Item& Pedido::operator[](size_t index) {
    if (index >= itens.size()) {
        throw std::out_of_range("Indice do item fora do intervalo do pedido.");
    }
    return itens[index];
}

const Item& Pedido::operator[](size_t index) const {
    if (index >= itens.size()) {
        throw std::out_of_range("Indice do item fora do intervalo do pedido.");
    }
    return itens[index];
}

// SOBRECARGA DE OPERADOR
std::ostream& operator<<(std::ostream& os, const Pedido& pedido) {
    os << "--- Pedido #" << pedido.codigo << " ---\n";
    if (pedido.cliente_p) {
        // Usa o operator<< da classe Cliente (que é polimórfico)
        os << *pedido.cliente_p << "\n";
    }

    os << "\nItens do Pedido:\n";
    double subtotal = 0;
    for (const auto& item : pedido.itens) {
        os << " - " << item << '\n'; // Usa o operator<< de Item
        subtotal += item.getValorTotal();
    }
    
    os << "\nSubtotal: R$ " << subtotal << "\n";
    if (pedido.cliente_p) {
       double taxa = pedido.cliente_p->getDesconto();
       os << "Desconto (" << (taxa * 100) << "%): R$ " << subtotal * taxa << "\n";
    }
    
    os << "Valor Final: R$ " << pedido.valorFinal << "\n"
       << "---------------------\n";
    return os;
}