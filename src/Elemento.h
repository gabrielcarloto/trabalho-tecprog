#pragma once
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
namespace Listas{
template<class TL>
class Elemento{
    private:
        Elemento<TL>* pProx;
        TL* pInfo;
    public:
        void Elemento<TL> get_previous();
        void Elemento<TL> get_next();
        void Elemento<TL> set_next(Elemento<TL>* pn);
        void Elemento<TL> set_info(TL* Info);
        TL* get_Info();
        Elemento ( );
        ~Elemento ( );

};
template<class TL>
Elemento<TL>::Elemento()
{
   pProx = NULL;
}
template<class TL>
Elemento<TL>::~Elemento()
{
   pProx = NULL;
}
template<class TL>
TL* Elemento<TL>::get_Info() {
    return pInfo;
}
template<class TL>
void Elemento<TL>::set_info(TL* Info){
    pInfo = Info;
}
template<class TL>
Elemento<TL>*::get_next(){
    return pProx;
}
template<class TL>
Elemento<TL>*::get_previous(){
    return pProx;
}
template<class TL>
void Elemento<TL>::set_next(Element<TL>* pn){
    pProx = pn;
}
}
