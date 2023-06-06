#pragma once
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<class T>
class elemento{
    private:
        elemento<T>* p_next;
        elemento<T>* p_previous;
    public:
        void elemento<T> get_previous();
        void elemento<T> get_next();
        void elemento<T> set_previous(elemento<T>* pp);
        void elemento<T> set_next(elemento<T>* pn);
        elemento ( );
        ~elemento ( );

};
template<class T>
elemento<T>::elemento()
{
   p_next= NULL;  p_previous= NULL;
}
template<class T>
elemento<T>::~elemento()
{
   p_next= NULL;  p_previous= NULL;
}
template<class T>
void elemento<T>::get_previous() {
    return p_previous;
}
template<class T>
void elemento<T>::get_next(){
    return p_next;
}
template<class T>
void elemento<T>::set_previous(elemento<T>* pp) {
    p_previous = pp;
}
template<class T>
void elemento<T>::set_next(elemento<T>* pn) {
    p_next = pn;
}
