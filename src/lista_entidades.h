#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include "elemento.h"
#include "listas.h"
#include "Entidade.h"
using namespace std;

class lista_entidades {
    private:
        listas<Entidade>* lista_ente;
    public:
        void lista_entidades();
        void ~lista_entidades();
        void incluir(Entidade *pE);
        void lista();
};
void lista_entidades::lista_entidades() {}
void lista_entidades::~lista_entidades(){}

void lista_entidades::incluir(Entidade *pE){
    if(pE != NULL) {
       lista_ente->inclui(pE);
    }
}
void lista_entidades::lista() {
    elemento<Entidade> *it = NULL;
    Entidade aux = NULL;
    it = lista_ente->first;

    while (it != NULL){
        //DO SOMETHING
        it = it->p_next;
    }
}
