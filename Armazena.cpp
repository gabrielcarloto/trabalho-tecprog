#include <iostream>
#include "Armazena.h"
Armazena::Armazena():originator_(originator){

}
Armazena::~Armazena(){
    for(auto m : mementos_){
        delete m;
    }
}
void Armazena::backup(){
    this->mementos_.push_back(this->originator_->salva());
}
void Armazena::undo(){
    if(!this->mementos_.size()) {
        return;
    }

    Memento *p;
    this->p.pop_back();
    cout << "Retrato do jogo nesse interim"<< p->nome() << endl;
    try {
        this->originator_->recupera(memento);
    } catch(...) {
        this->undo();
    }
}
void Armazena::historico() {
    cout << "Lista de mementos" << endl;
    for (Memento *memento : this->mementos_) {
        cout << "LIFO primeito evento da pilha" << memento->nome() << endl;
    }
}
