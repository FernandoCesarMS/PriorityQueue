#include "fila_de_prioridade.hpp"

FilaDePrioridade::FilaDePrioridade(){
    this->size = 0;
    this->first = nullptr;
}

string FilaDePrioridade::primeiro() const{
    return this->first.nome;
}
