#include "item.h"

Item::Item(const Produto& produto, int quantidade)
    : produto_p(produto), quantidade_q(quantidade) {
    atualizarValorTotal();
}

void Item::atualizarValorTotal() {
    valorTotal = quantidade_q * produto_p.getPreco();
}

Produto Item::getProduto() const { return produto_p; }
int Item::getQuantidade() const { return quantidade_q; }

double Item::getValorTotal() const { return valorTotal; }

int Item::getCodigo() const { return produto_p.getCodigo(); } 

void Item::adicionarQuantidade(int quantidadeAdicional) {
    if (quantidadeAdicional > 0) {
        this->quantidade_q += quantidadeAdicional;
        atualizarValorTotal();
    }
}

// SOBRECARGA DE OPERADOR
std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << "Item: " << item.produto_p.getNome() 
       << " | Qtd: " << item.quantidade_q
       << " | Valor Total: R$ " << item.valorTotal;
    return os;
}