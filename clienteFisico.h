#ifndef CLIENTE_FISICO_H
#define CLIENTE_FISICO_H

#include "cliente.h"

class ClienteFisico : public Cliente {
private:
    std::string CPF;

public:
    // CONSTRUTOR
    ClienteFisico(int codigo, const std::string& nome, const Endereco& endereco, const std::string& cpf);
    
    void imprimir(std::ostream& os) const override;
    double getDesconto() const override;

    // MÉTODO ESTÁTICO: Valida o formato de um CPF
    static bool validarCPF(const std::string& cpf);
};

#endif