#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>
#include "endereco.h"

class Cliente {
protected:
    int codigo;
    std::string nome;
    Endereco m_endereco;
    // MEMBRO ESTÁTICO: Conta o total de clientes instanciados
    static int totalClientes;

public:
    // CONSTRUTOR
    Cliente(int codigo, const std::string& nome, const Endereco& endereco);

    // DESTRUTOR
    virtual ~Cliente();

    int getCodigo() const;
    std::string getNome() const;

    // MÉTODO ESTÁTICO: Retorna o número total de clientes
    static int getTotalClientes();
    
    // FUNÇÃO FRIEND: Permite que o operador << acesse membros privados/protegidos
    friend std::ostream& operator<<(std::ostream& os, const Cliente& cliente);

    // Auxiliar para polimorfismo na impressão
    virtual void imprimir(std::ostream& os) const = 0; 
    virtual double getDesconto() const = 0;
};

#endif