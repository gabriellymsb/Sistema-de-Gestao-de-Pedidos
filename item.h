#ifndef ITEM_H
#define ITEM_H

#include "produto.h"
#include <iostream>

class Item {
private:
    Produto produto_p;
    int quantidade_q;
    double valorTotal;

    void atualizarValorTotal();

public:
    Item(const Produto& produto, int quantidade);

    Produto getProduto() const;
    int getQuantidade() const;
    double getValorTotal() const;
    int getCodigo() const; // COMPATIBILIDADE COM O GERENCIADOR

    void adicionarQuantidade(int quantidadeAdicional);

    // FUNÇÃO FRIEND
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

#endif