#pragma once
#include <iostream>
#include "Observer.h"
#include "Entidade.h"
#include "Gerenciador_Grafico.h"
#include  "Gerenciador_Colisoes.h"
#include  "Jogo.h"
#include  "Obstaculo.h"
#include  "Obstaculo_Facil.h"
#include  "Obstaculo_Medio.h"
#include  "Chao.h"
#include  "Projetil.h"
#include  "Fase.h"
#include  "Fase_Primeira.h"
#include  "Fase_Segunda.h"
#include  "Armazena.h"
#include  "originator.h"
#include  <SFML/System/Vector2.hpp>

using namespace std;
class fachada {
    private:
        /*Jogo jogo;
        Entidade entidade;
        Gerenciador_Grafico *pGG;
        Gerenciador_Colisoes *pGC;
        Obstaculo_Facil obst_f;
        Obstaculo_Medio obst_m;
        Chao chao;
        Inimigo inimigo;
        Inim_Facil inim_facil;
        Jogador jogador;
        Inim_Dificil inim_dificil;
        */
        Jogo jogo;
        Fase_Primeira *fP;
        Fase_Segunda *fS;
        float posX_primeira;
        float posY_primeira;
        float posX_segunda;
        float posY_segunda;
        string name_jogador;
        unsigned int pontos = 0;
        unsigned int numeroJogador;
        const char *cP;
        const char *cS;

    public:
        fachada();
        ~fachada();
          void executar();

          void fim_jogo();
          char* mapa_salvo();
          void carregarMapa(const char *);
          void carrega_fundo();
          void carregarBackground();

          void set_posicaoJogadores_pfase();
          void set_posicaoJogadores_sfase();
          float* getX_posicaoJogadores();
          float* getY_posicaoJogadores();
};
