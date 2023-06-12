#include<iostream>
#include<string>
#include"Fase.h"
#include"Memento.hpp"
#include"checkpoint.h"
using namespace std;
class originator {
	private:
		//fase *ptr_fases;
        fachada state_;
        //fachada estado;
	public:
		originator(string state);
        void doSomething();
        Memento *salva();
        void recupera();
        void seta_ptr();
};

