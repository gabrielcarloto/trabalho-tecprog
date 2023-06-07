#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include "Elemento.h"
#include "Lista.h"
#include "Entidade.h"
using namespace std;
namespace Jogo{
namespace Listas{
class ListaEntidades{
    private:
        Lista<Entidade>* lista_ente;
    public:
        void ListaEntidades();
        void ~ListaEntidades();
        void incluir(Entidade *pE);
        void percorre();
};
void ListaEntidades::ListaEntidades() {}
void ListaEntidades::~ListaEntidadess(){
    lista_ente->limpa();
}

void ListaEntidades::incluir(Entidade *pE){
    Lista<Entidade> p;
    if(pE != NULL) {
       p->inclui_Info(pE);
    }
}
void lista_entidades::percorre() {
    Lista<Entidade> *it = NULL;
    lista_ente->listar();
}
}
}
