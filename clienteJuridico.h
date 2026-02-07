#ifndef CLIENTE_JURIDICO_H
#define CLIENTE_JURIDICO_H

#include "cliente.h"

class ClienteJuridico : public Cliente {
private:
    std::string CNPJ;

public:
    ClienteJuridico(int codigo, const std::string& nome, const Endereco& endereco, const std::string& cnpj);
    
    void imprimir(std::ostream& os) const override;
    double getDesconto() const override;

    // MÉTODO ESTÁTICO: Valida o formato de um CNPJ
    static bool validarCNPJ(const std::string& cnpj);
};

#endif