#include "Inim_Facil.h"
#include "../uteis.h"
#include "Jogador.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <utility>

constexpr int MALDADE_PADRAO_FACIL = 3;
constexpr float DISTANCIA_X_PERSEGUIR_JOGADOR = TAMANHO_TILE * 3,
                DISTANCIA_Y_PERSEGUIR_JOGADOR =
                    static_cast<float>(TAMANHO_TILE) / 2;

namespace Jogo::Entidades::Personagens {
Sapo::Sapo(const char *path, sf::Vector2f pos, float velo, bool pula,
           float fator)
    : Inimigo(path, MALDADE_PADRAO_FACIL, pos, velo), pulaAleatoriamente(pula),
      fatorPulo(fator) {
  distanciaPerseguirJogadorX = DISTANCIA_X_PERSEGUIR_JOGADOR;
  distanciaPerseguirJogadorY = DISTANCIA_Y_PERSEGUIR_JOGADOR;
}

Sapo::Sapo(const char *path, sf::IntRect lim, sf::Vector2f pos, float velo,
           bool pula, float fator)
    : Inimigo(path, lim, MALDADE_PADRAO_FACIL, pos, velo),
      pulaAleatoriamente(pula), fatorPulo(fator) {
  distanciaPerseguirJogadorX = DISTANCIA_X_PERSEGUIR_JOGADOR;
  distanciaPerseguirJogadorY = DISTANCIA_Y_PERSEGUIR_JOGADOR;
}

void Sapo::executar() { mover(); }

float Sapo::perseguirJogador(sf::Vector2f posJogador) {
  float direcao = Inimigo::perseguirJogador(posJogador);

  if (pulaAleatoriamente && podePular && Uteis::chance(1))
    pular(TAMANHO_TILE * fatorPulo);

  return direcao;
}

void Sapo::moverAleatoriamente() {
  Inimigo::moverAleatoriamente();

  if (pulaAleatoriamente && podePular && Uteis::chance(1))
    pular(TAMANHO_TILE * fatorPulo);
}
} // namespace Jogo::Entidades::Personagens
