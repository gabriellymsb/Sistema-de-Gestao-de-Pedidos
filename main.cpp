#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// Novos includes
#include "utils.h"
#include "excecoes.h"
#include "gerenciador.h"

// Includes do projeto
#include "clienteFisico.h"
#include "clienteJuridico.h"
#include "produto.h"
#include "pedido.h"
#include "endereco.h"

// Protótipos de funções
void cadastrarCliente(std::vector<std::unique_ptr<Cliente>>& clientes, bool isFisico);
void cadastrarProduto(Gerenciador<Produto>& produtos);
void criarPedido(std::vector<std::unique_ptr<Cliente>>& clientes, Gerenciador<Pedido>& pedidos, Gerenciador<Produto>& produtos);
void listarClientes(const std::vector<std::unique_ptr<Cliente>>& clientes);
void reporEstoque(Gerenciador<Produto>& produtos);

int main() {
    std::vector<std::unique_ptr<Cliente>> clientes;
    Gerenciador<Produto> gerenciadorProdutos;
    Gerenciador<Pedido> gerenciadorPedidos;
    int opcao;

    do {
        std::cout << "\n=== Sistema de Gestao de Pedidos (v2.0) ===\n"
                  << "Clientes Cadastrados: " << Cliente::getTotalClientes() << "\n"
                  << "1. Cadastrar Cliente Fisico\n"
                  << "2. Cadastrar Cliente Juridico\n"
                  << "3. Cadastrar Produto\n"
                  << "4. Criar Novo Pedido\n"
                  << "5. Listar Clientes\n"
                  << "6. Listar Produtos\n"
                  << "7. Listar Pedidos\n"
                  << "8. Repor Estoque de Produto\n"
                  << "0. Sair\n";
        
        opcao = lerEntrada<int>("Escolha uma opcao: ");

        try {
            switch(opcao) {
                case 1: cadastrarCliente(clientes, true); break;
                case 2: cadastrarCliente(clientes, false); break;
                case 3: cadastrarProduto(gerenciadorProdutos); break;
                case 4: criarPedido(clientes, gerenciadorPedidos, gerenciadorProdutos); break;
                case 5: listarClientes(clientes); break;
                case 6: std::cout << "\n--- Lista de Produtos ---\n"; gerenciadorProdutos.listarTodos(); break;
                case 7: std::cout << "\n--- Lista de Pedidos ---\n"; gerenciadorPedidos.listarTodos(); break;
                case 8: reporEstoque(gerenciadorProdutos); break;
                case 0: std::cout << "Encerrando sistema...\n"; break;
                default: std::cout << "Opcao invalida!\n"; break;
            }
        } catch (const std::exception& e) {
            std::cerr << "\n!!! OCORREU UM ERRO: " << e.what() << " !!!\n";
        }

    } while(opcao != 0);

    return 0;
}

void cadastrarCliente(std::vector<std::unique_ptr<Cliente>>& clientes, bool isFisico) {
    std::cout << (isFisico ? "\n--- Cadastro Cliente Fisico ---\n" : "\n--- Cadastro Cliente Juridico ---\n");
    
    int codigo = clientes.size() + 1;
    std::string nome = lerString("Nome: ");
    std::string doc = lerString(isFisico ? "CPF (11 digitos): " : "CNPJ (14 digitos): ");
    
    std::cout << "\nEndereco:\n";
    std::string rua = lerString("Rua: ");
    int numero = lerEntrada<int>("Numero: ");
    std::string bairro = lerString("Bairro: ");
    std::string cidade = lerString("Cidade: ");
    
    Endereco endereco(rua, numero, bairro, cidade);

    if (isFisico) {
        clientes.push_back(std::make_unique<ClienteFisico>(codigo, nome, endereco, doc));
    } else {
        clientes.push_back(std::make_unique<ClienteJuridico>(codigo, nome, endereco, doc));
    }
    std::cout << "Cliente cadastrado com sucesso!\n";
}

void cadastrarProduto(Gerenciador<Produto>& produtos) {
    std::cout << "\n--- Cadastro de Produto ---\n";
    int codigo = produtos.getProximoCodigo();
    std::string nome = lerString("Nome: ");
    double preco = lerEntrada<double>("Preco: R$ ");
    int cat = lerEntrada<int>("Categoria (1-Alimento 2-Bebida 3-Eletronico 4-Vestuario 5-Livro 6-Limpeza): ");
    int estoque = lerEntrada<int>("Quantidade em estoque: ");

    produtos.adicionar(codigo, nome, preco, static_cast<Categoria>(cat - 1), estoque);
    std::cout << "Produto cadastrado com sucesso!\n";
}

void criarPedido(std::vector<std::unique_ptr<Cliente>>& clientes, Gerenciador<Pedido>& pedidos, Gerenciador<Produto>& produtos) {
    if (clientes.empty()) throw std::runtime_error("Cadastre um cliente primeiro!");
    if (produtos.getTodos().empty()) throw std::runtime_error("Cadastre um produto primeiro!");

    std::cout << "\n--- Criar Novo Pedido ---\n";
    listarClientes(clientes);

    int idxCliente = lerEntrada<int>("Indice do cliente: ");

    if (idxCliente < 0 || static_cast<size_t>(idxCliente) >= clientes.size()) 
        throw ItemNaoEncontradoException("Indice de cliente invalido!");

    int codigoPedido = pedidos.getProximoCodigo();
    Pedido novoPedido(codigoPedido, clientes[idxCliente].get()); // Cria novo pedido
    
    int codigoProduto;
    do {
        std::cout << "\n--- Produtos Disponiveis ---\n";
        produtos.listarTodos();
        codigoProduto = lerEntrada<int>("Codigo do produto para adicionar (-1 para finalizar): ");
        
        if (codigoProduto != -1) {
            Produto& produto = produtos.buscarPorCodigo(codigoProduto); // Lança exceção se não achar
            int quantidade = lerEntrada<int>("Quantidade: ");
            novoPedido.adicionarItem(produto, quantidade); // Lança exceção se não houver estoque
            std::cout << "Item '" << produto.getNome() << "' adicionado!\n";
        }
    } while (codigoProduto != -1);
    
    pedidos.adicionar(std::move(novoPedido)); // Adiciona o pedido ao gerenciador
    std::cout << "\nPedido criado com sucesso!\n";
    std::cout << pedidos.buscarPorCodigo(codigoPedido); // Mostra o pedido recém-criado
}

void listarClientes(const std::vector<std::unique_ptr<Cliente>>& clientes) {
    std::cout << "\n--- Lista de Clientes ---\n";
    if (clientes.empty()) {
        std::cout << "Nenhum cliente cadastrado.\n";
        return;
    }
    for (size_t i = 0; i < clientes.size(); ++i) {
        std::cout << "--> Indice [" << i << "]\n" << *clientes[i] << "\n";
    }
}

void reporEstoque(Gerenciador<Produto>& produtos) {
    std::cout << "\n--- Reposicao de Estoque ---\n";
    produtos.listarTodos();
    int codigo = lerEntrada<int>("Codigo do produto: ");
    
    Produto& produto = produtos.buscarPorCodigo(codigo); // Lança exceção se não achar
    int quantidade = lerEntrada<int>("Quantidade a adicionar: ");
    
    produto += quantidade; // Usa o operador sobrecarregado
    
    std::cout << "Estoque atualizado com sucesso!\n";
    std::cout << "Novo estado do produto: " << produto << "\n";
}