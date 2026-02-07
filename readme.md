# Sistema de Gestão de Pedidos (C++)

Este projeto é um **Sistema de Gestão de Pedidos** desenvolvido em **C++**, utilizando conceitos avançados de **Programação Orientada a Objetos (POO)**, **templates**, **smart pointers**, **tratamento de exceções** e **sobrecarga de operadores**.

O sistema permite o cadastro e gerenciamento de **clientes físicos e jurídicos**, **produtos**, **pedidos** e **controle de estoque**, tudo por meio de um **menu interativo em terminal**.

---

## 🎯 Objetivos do Projeto

* Aplicar conceitos fundamentais e avançados de POO em C++
* Utilizar `std::unique_ptr` para gerenciamento seguro de memória
* Trabalhar com **herança**, **polimorfismo** e **composição**
* Implementar um **gerenciador genérico** usando templates
* Praticar **tratamento de exceções personalizadas**
* Desenvolver um sistema modular e extensível

---

## 🛠️ Funcionalidades

* 📌 Cadastro de **Cliente Físico** (CPF)
* 📌 Cadastro de **Cliente Jurídico** (CNPJ)
* 📌 Cadastro e listagem de **Produtos**
* 📌 Criação de **Pedidos** com múltiplos itens
* 📌 Controle e reposição de **Estoque**
* 📌 Listagem de clientes, produtos e pedidos
* 📌 Tratamento de erros com mensagens claras ao usuário

---

## 🧱 Estrutura do Projeto
```
├── main.cpp
├── cliente.h
├── clienteFisico.h
├── clienteJuridico.h
├── endereco.h
├── produto.h
├── pedido.h
├── gerenciador.h
├── excecoes.h
├── utils.h
```
---

## 🧠 Principais Conceitos Utilizados

### 🔹 Programação Orientada a Objetos

* **Herança**: `ClienteFisico` e `ClienteJuridico` herdam de `Cliente`
* **Polimorfismo**: uso de métodos virtuais e ponteiros para classe base
* **Composição**: `Cliente` possui um `Endereco`, `Pedido` possui itens

### 🔹 Templates

* Classe `Gerenciador<T>` para gerenciar diferentes tipos de entidades (Produto, Pedido)

### 🔹 Smart Pointers

* Uso de `std::unique_ptr<Cliente>` para evitar vazamentos de memória

### 🔹 Exceções

* Exceções personalizadas para itens não encontrados e erros de estoque
* Blocos `try/catch` no menu principal

### 🔹 Sobrecarga de Operadores

* `operator<<` para impressão de objetos
* `operator+=` para reposição de estoque de produtos

---

## 📋 Menu do Sistema

```
=== Sistema de Gestao de Pedidos (v2.0) ===
1. Cadastrar Cliente Fisico
2. Cadastrar Cliente Juridico
3. Cadastrar Produto
4. Criar Novo Pedido
5. Listar Clientes
6. Listar Produtos
7. Listar Pedidos
8. Repor Estoque de Produto
0. Sair
```

---

## ▶️ Como Compilar e Executar

### Compilação (Linux / g++)

```bash
g++ -std=c++17 main.cpp -o sistema
```

> Certifique-se de que todos os arquivos `.h` e `.cpp` estejam no mesmo diretório.

### Execução

```bash
./sistema
```

---

## ⚠️ Observações Importantes

* O sistema roda totalmente em **modo texto (terminal)**
* As entradas do usuário são validadas por funções auxiliares em `utils.h`
* Erros como índices inválidos, produtos inexistentes ou falta de estoque são tratados por exceções

---

## 👩‍💻 Autoria

Projeto desenvolvido pelos alunos Gabrielly Maria, Isabela Oliveira e Matheo Duarte durante a matéria de Programação Orientada a Objetos.

---

