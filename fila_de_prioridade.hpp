#pragma once

#include <string>

using std::string;

// Define como cada nó da lista encadeada é implementado.
struct No;

class FilaDePrioridade {
 public:
 
  // Constrói uma fila vazia.
  FilaDePrioridade();

  // Retorna o elemento de maior prioridade.
  string primeiro() const;

  // Retorna o número de elementos na fila.
  int tamanho() const;

  // Testa se a fila está vazia.
  bool vazia() const;

  // Remove o elemento de maior prioridade.
  void RemoverPrimeiro();

  // Insere um elemento s fila com prioridade p;
  void Inserir(int p, string s);

  // Remove todos os elementos da fila.
  void Limpar();

 private:
  int size;  // Número de elementos da fila.
  No* first; // Ponteiro para o primeiro da lista encadeada. 
};