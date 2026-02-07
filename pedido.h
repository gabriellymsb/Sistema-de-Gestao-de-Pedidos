#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include "item.h"
#include "cliente.h"
#include <iostream>

class Pedido {
private:
    int codigo;
    Cliente* cliente_p;
    std::vector<Item> itens;
    double valorFinal;

    void calcularValorFinal();

public:
    Pedido(int codigo, Cliente* cliente);

    int getCodigo() const;
    void adicionarItem(Produto& produto, int quantidade); // Modificado
    
    // SOBRECARGA DE OPERADOR: Acesso com verificação de limites
    Item& operator[](size_t index);
    const Item& operator[](size_t index) const;

    // FUNÇÃO FRIEND
    friend std::ostream& operator<<(std::ostream& os, const Pedido& pedido);
};

#endif