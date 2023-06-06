#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include "elemento.h"
using namespace std;
template<class T>
class listas{
    private:
        elemento<T>* first;
        elemento<T>* second;
        elemento<T>*partner;
    public:
        void lista();
        void ~lista();
        void inclui(elemento<T>* current);
        void limpa();
        //void seta_afiliate();
};
template<class T>
void listas<T>::inclui(elemento<T>* current) {
    if (first == NULL) {
            first = current;
            second = current;
            current->p_next = NULL;
            current->p_previous = NULL;
    }else {
        second->p_next = current;
        current->p_previous = second;
        second = p;
        second->p_next = NULL;
        second->p_previous = NULL;
    }
}
void listas<T>::limpa() {
    elemento<T>* temp;
    elemento<T>* aux;
    temp = first;
    aux = temp;

    while (temp != NULL){
        aux = temp->p_next;
        delete*(temp);
        temp = aux;
    }
    first = NULL;
    second = NULL;
}
/*void listas::seta_afiliate(elemento<T>* p){
    partner = p;
}*/
