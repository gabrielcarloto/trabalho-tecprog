#pragma once
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
namespace Listas{
template<class TL>
class Elemento{
    private:
        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;
    public:
        void Elemento<TL> get_previous();
        void Elemento<TL> get_next();
        void Elemento<TL> set_previous(Elemento<TL>* pp);
        void Elemento<TL> set_next(Elemento<TL>* pn);
        Elemento ( );
        ~Elemento ( );

};
template<class TL>
Elemento<TL>::Elemento()
{
   pPrimeiro= NULL;  pUltimo= NULL;
}
template<class TL>
Elemento<TL>::~Elemento()
{
   pPrimeiro= NULL;  pUltimo= NULL;
}
template<class TL>
void Elemento<TL>::get_previous() {
    return pPrimeiro;
}
template<class TL>
void Elemento<TL>::get_next(){
    return pUltimo;
}
template<class TL>
void Elemento<TL>::set_previous(Elemento<TL>* pp) {
    pUltimo = pp;
}
template<class TL>
void Elemento<TL>::set_next(Elemento<TL>* pn) {
    pUltimo = pn;
}
}
