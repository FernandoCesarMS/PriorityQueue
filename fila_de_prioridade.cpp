#include "fila_de_prioridade.h"
#include <vector>

struct No{
  string name;
  No* nextNode;
  int age;
  No(){
      age = -1;
      name = "";
      nextNode = nullptr;
  }
  No(int Age, string Name){
      this->age = Age;
      this->name = Name;
      this->nextNode = nullptr;
  }
  No(int Age, string Name, No* NextNode){
      this->age = Age;
      this->name = Name;
      this->nextNode = NextNode;
  }
};
FilaDePrioridade::FilaDePrioridade(){
    this->size = 0;
    this->first = nullptr;
}

string FilaDePrioridade::primeiro() const{
    if (!vazia()){
        string biggestAgeName = "";
        int valueToBeRemoved = 0, biggestAge = -1;
        No* provisionalFirst = this->first;
        for (int i = 0; i < this->tamanho(); i++){
            if (provisionalFirst->age >= biggestAge){
                biggestAge = provisionalFirst->age;
                valueToBeRemoved = i;
                biggestAgeName = provisionalFirst->name;
            }
            if (provisionalFirst->nextNode != nullptr)
                provisionalFirst = new No(provisionalFirst->nextNode->age, 
                provisionalFirst->nextNode->name, 
                provisionalFirst->nextNode->nextNode);
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
    if(this->tamanho() == 0)
        return true;
    else
        return false;
}

void FilaDePrioridade::RemoverPrimeiro(){
    int valueToBeRemoved = 0, biggestAge = -1;
    std::vector <int> oldQueueAges;
    std::vector <string> oldQueueNames;
    No* provisionalFirst = this->first;
    for (int i = 0; i < this->tamanho(); i++){
        oldQueueAges.push_back(provisionalFirst->age);
        oldQueueNames.push_back(provisionalFirst->name);
        if (provisionalFirst->age >= biggestAge){
            biggestAge = provisionalFirst->age;
            valueToBeRemoved = i;
        }
        if (provisionalFirst->nextNode != nullptr)
            provisionalFirst = new No(provisionalFirst->nextNode->age, 
            provisionalFirst->nextNode->name, 
            provisionalFirst->nextNode->nextNode);
    }
    this->Limpar();
    for (int i = oldQueueAges.size() - 1; i >= 0 ; i--)
        if (i != valueToBeRemoved)
            this->Inserir(oldQueueAges[i],oldQueueNames[i]);
}

void FilaDePrioridade::Inserir(int p, string s){
    if (this->vazia())
        this->first = new No(p,s);
    else
        this->first = new No(p,s,new No(this->first->age, this->first->name, this->first->nextNode));
    size++;
}

void FilaDePrioridade::Limpar(){
    this->size = 0;
    this->first = new No();
}

