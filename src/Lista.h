#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include "Elemento.h"
using namespace std;
namespace Jogo {
namespace Listas{
class Elemento;
template<class TL>
class Lista{
    private:
        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;
    public:
        void Lista();
        void ~Lista();
        void inclui(elemento<T>* pE);
        void listar();
        void limpa();
        void inclui_Info(TL* pInfo);
        //void seta_afiliate();
};
template<class TL>
Lista<TL>::Lista(){
    pPrimeiro = NULL;
    pUltimo = NULL;
}
template<class TL>
Lista<TL>::~Lista(){
    limpa();
}
template<class TL>
void Lista<TL>::inclui(Elemento<TL>* pE) {
    if (pPrimeiro == NULL) {
            pPrimeiro = pE;
            pUltimo = pPrimeiro;
    }else {
        pE->set_previous(pUltimo);
        pUltimo->set_next(pE);
        pUltimo = pUltimo->get_next();
    }
}
template<class TL>
void Lista<TL>::limpa() {
    Elemento<TL>* temp;
    Elemento<TL>* aux;
    temp = pPrimeiro;
    aux = temp;

    while (temp != NULL){
        aux = temp->p_next;
        delete*(temp);
        temp = aux;
    }
    pProximo = NULL;
    PUltimo = NULL;
}
template<class TL>
void Lista<TL>::listar(){
    Elemento<TL>* percorre;
    percorre = pPrimeiro;
    if(pPrimeiro != NULL) {
        while(percorre != NULL) {
            cout << "Elemento da lista" << percorre->get_Info <<endl;
            percorre = percorre->get_next;
        }
    }
}
template<class TL>
void Lista<TL>::inclui_Info(TL* pInfo){
    if(pInfo == NULL) {
    Elemento<TL>* pE = NULL;
    pE = new Elemento<TL>();
    pE->set_Info(pInfo);
    inclui(pE);
    }else{
        cout << "ERROR" << endl;
    }
}
}
}
