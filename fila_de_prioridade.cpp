#include "fila_de_prioridade.h"
#include <iostream>

FilaDePrioridade::FilaDePrioridade(){
    this->size = 0;
    this->first = nullptr;
}

string FilaDePrioridade::primeiro() const{
    if (!vazia())
        return this->first->nome;
    else
        return "";
}

int FilaDePrioridade::tamanho() const{
    return this->size;
}
  
bool FilaDePrioridade::vazia() const{
    if(this->size == 0)
        return true;
    else
        return false;
}

void FilaDePrioridade::RemoverPrimeiro(){
    if (!(this->vazia())){
        if (this->tamanho() != 1){
            No* aux = new No();
            aux->nome = this->first->proximo->nome;
            aux->idade = this->first->proximo->idade;
            aux->proximo = this->first->proximo->proximo;
            this->first = aux;
        }
        else{
            No* aux = new No();
            aux->nome = nullptr;
            aux->idade = 0;
            aux->proximo = nullptr;
            this->first = aux;
        }
        this->size--;
    } 
}

void FilaDePrioridade::Inserir(int p, string s){
    if (this->vazia())
        this->first = new No(p,s);
    else
        this->first = new No(p,s,new No(this->first->idade, this->first->nome, this->first->proximo));
    size++;
}

void FilaDePrioridade::Limpar(){
    this->size = 0;
    No* aux = new No();
    aux->nome = nullptr;
    aux->idade = 0;
    aux->proximo = nullptr;
    this->first = aux;
}

