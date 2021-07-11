#include "fila_de_prioridade.hpp"

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
            aux->idade = NULL;
            aux->proximo = nullptr;
            this->first = aux;
        }
        this->size--;
    } 
}

void FilaDePrioridade::Inserir(int p, string s){
    if (this->vazia()){
        this->first->nome = s;
        this->first->idade = p;
        this->first->proximo = nullptr;
    }
    else{
        No* aux = new No();
        aux->nome = this->first->nome;
        aux->idade = this->first->idade;
        aux->proximo = this->first->proximo;
        this->first->nome = s;
        this->first->idade = p;
        this->first->proximo = aux;
    }
}

void FilaDePrioridade::Limpar(){
    this->size = 0;
    No* aux = new No();
    aux->nome = nullptr;
    aux->idade = NULL;
    aux->proximo = nullptr;
    this->first = aux;
}

