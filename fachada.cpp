#include <iostream>
#include "fachada.h"

fachada::fachada() {
    fP = NULL;
    fS = NULL;
}
fachada::~fachada() {
    delete(jogo);
}
fachada::executar() {

}
void fachada::executar(){

}
void fachada::fim_jogo(){
      EVENTOS jogador_game_over;
      if(jogador_game_over == (JOGADOR_FINALIZAR_FASE || JOGADOR_GAME_OVER)){
            set_posicaoJogadores();
      }
}


char* fachada::mapa_salvo(){
    const char cP;
    const char cS;
    fP->carregarMapa(&cP);
    fS->carregarMapa(&cS);
    return cP;
}

void fachada::set_posicaoJogadores_pfase() {
    fP = fP->listaJogadores;
    posX_primeira =  fP->x;
    posY_primeira = fP->y;
    name_jogador = fP->nome;
    numeroJogador = fP->numeroJogador;
    pontos = fP->pontos;
}
void fachada::set_posicaoJogadores_sfase() {
    fS = fS->listaEntidades;
    posX_segunda = fS->x;
    posY_segunda = fS->y;
    name_jogador = fS->nome;
    numeroJogador = fS->numeroJogador;
    pontos = fS->pontos;
}
float* fachada::getX_posicaoJogadores_pfase() {
    return posX_primeira;
}
float* fachada::getY_posicaoJogadores_pfase() {
    return posY_primera;
}
float* fachada::getX_posicaoJogadores_sfase() {
    return posX_segunda;
}
float* fachada::getY_posicaoJogadores_sfase() {
    return posY_segunda;
}
