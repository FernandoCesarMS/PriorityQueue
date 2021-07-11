#include "fila_de_prioridade.h"
#include <iostream>
#include <vector>

FilaDePrioridade::FilaDePrioridade(){
    this->size = 0;
    this->first = nullptr;
}

string FilaDePrioridade::primeiro() const{
    if (!vazia()){
        string biggestAgeName = "";
        int valueToBeRemoved = 0, biggestAge = -1;
        No* aux = this->first;
        for (int i = 0; i < this->tamanho(); i++){
            if (aux->idade >= biggestAge){
                biggestAge = aux->idade;
                valueToBeRemoved = i;
                biggestAgeName = aux->nome;
            }
            if (aux->proximo != nullptr)
                aux = new No(aux->proximo->idade, aux->proximo->nome, aux->proximo->proximo);
        }
        return biggestAgeName;
    }
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
    int valueToBeRemoved = 0, biggestAge = -1;
    std::vector <int> oldQueueAges;
    std::vector <string> oldQueueNames;
    No* aux = this->first;
    for (int i = 0; i < this->tamanho(); i++){
        oldQueueAges.push_back(aux->idade);
        oldQueueNames.push_back(aux->nome);
        if (aux->idade >= biggestAge){
            biggestAge = aux->idade;
            valueToBeRemoved = i;
        }
        if (aux->proximo != nullptr)
            aux = new No(aux->proximo->idade, aux->proximo->nome, aux->proximo->proximo);
    }
    this->Limpar();
    for (int i = oldQueueAges.size() - 1; i >= 0 ; i--){
        if (i != valueToBeRemoved){
            this->Inserir(oldQueueAges[i],oldQueueNames[i]);
        }
    }
}

void FilaDePrioridade::Inserir(int p, string s){
    if (this->vazia()){
        this->first = new No(p,s);
    }
    else{
        this->first = new No(p,s,new No(this->first->idade, this->first->nome, this->first->proximo));
    }
    size++;
}

void FilaDePrioridade::Limpar(){
    this->size = 0;
    this->first = new No();
}

