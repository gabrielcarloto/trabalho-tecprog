#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include"originator.hpp"
#include"checkpoint.hpp"

using namespace std;

originator::originator(string state) : state_(state) {

}
void originator::doSomething() {
    this->state_ = state_.fim_jogo();//gerenciar eventos
}
Memento* originator::salva() {
	return new checkpoint(this->state_);
}
void originator::recupera(Memento *memento) {
	this->state_ = memento->state();
	cout << "Mudado o estado" << endl;
}
