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
Inim_Facil::Inim_Facil(const char *path, sf::Vector2f pos, float velo,
                       bool pula)
    : Inimigo(path, MALDADE_PADRAO_FACIL, pos, velo), pulaAleatoriamente(pula) {
  distanciaPerseguirJogadorX = DISTANCIA_X_PERSEGUIR_JOGADOR;
  distanciaPerseguirJogadorY = DISTANCIA_Y_PERSEGUIR_JOGADOR;
}

Inim_Facil::Inim_Facil(const char *path, sf::IntRect lim, sf::Vector2f pos,
                       float velo, bool pula)
    : Inimigo(path, lim, MALDADE_PADRAO_FACIL, pos, velo),
      pulaAleatoriamente(pula) {
  distanciaPerseguirJogadorX = DISTANCIA_X_PERSEGUIR_JOGADOR;
  distanciaPerseguirJogadorY = DISTANCIA_Y_PERSEGUIR_JOGADOR;
}

void Inim_Facil::executar() { mover(); }

void Inim_Facil::perseguirJogador(sf::Vector2f posJogador) {
  Inimigo::perseguirJogador(posJogador);

  if (pulaAleatoriamente && podePular && Uteis::chance(1))
    pular(TAMANHO_TILE * 1.2);
}

void Inim_Facil::moverAleatoriamente() {
  Inimigo::moverAleatoriamente();

  if (pulaAleatoriamente && podePular && Uteis::chance(1))
    pular(TAMANHO_TILE * 1.2);
}

} // namespace Jogo::Entidades::Personagens
