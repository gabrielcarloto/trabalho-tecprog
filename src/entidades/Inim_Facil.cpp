#include "Inim_Facil.h"
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
Inim_Facil::Inim_Facil(const char *path, sf::Vector2f pos, float velo)
    : Inimigo(path, MALDADE_PADRAO_FACIL, pos, velo) {}

Inim_Facil::Inim_Facil(const char *path, sf::IntRect lim, sf::Vector2f pos,
                       float velo)
    : Inimigo(path, lim, MALDADE_PADRAO_FACIL, pos, velo) {}

void Inim_Facil::executar() { atualizarPosicao(); }

void Inim_Facil::mover() {
  auto jogadorProximo = jogadorMaisProximo();
  auto posJogadorProximo = jogadorProximo.first->getFigura().getPosition();

  if (std::abs(posJogadorProximo.y - y) <= DISTANCIA_Y_PERSEGUIR_JOGADOR &&
      jogadorProximo.second <= DISTANCIA_X_PERSEGUIR_JOGADOR) {
    return perseguirJogador(posJogadorProximo);
  }

  moverAleatoriamente();
}

void Inim_Facil::perseguirJogador(sf::Vector2f posJogador) {
  float direcao = posJogador.x > x ? 1 : -1;
  velFinal.x += velocidade * direcao;

  // TODO: talvez muito viajado isso mas eh engraçado
  if (podePular && std::rand() % 100 == 1)
    pular(TAMANHO_TILE * 1.2);
}

void Inim_Facil::moverAleatoriamente() {
  float direcaoAleatoria = std::rand() % 100 <= 5 ? 1 : -1;
  float direcao = direcaoAleatoria * (velFinal.x < 0 ? 1.f : -1.f);
  velFinal.x += velocidade / 2 * direcao;

  if (podePular && std::rand() % 100 == 1)
    pular(TAMANHO_TILE * 1.2);
}

std::pair<Jogador *, float> Inim_Facil::jogadorMaisProximo() {
  auto distJogadores = distanciaJogadores();

  if (!jogadores[1] || distJogadores.first < distJogadores.second)
    return std::make_pair(jogadores[0], distJogadores.first);

  return std::make_pair(jogadores[1], distJogadores.second);
}

void Inim_Facil::tomarDano() {
  num_vidas--;

  if (num_vidas <= 0)
    morrer();
}

void Inim_Facil::colidir(Entidade *pEnt, sf::Vector2f intersecao) {
  auto posObst = pEnt->getFigura().getPosition();
  // TODO: lidar com obstáculos danosos

  if (intersecao.x > intersecao.y) {
    x += intersecao.x * (posObst.x < x ? -1.f : 1.f);
    velFinal.x = 0;
  } else {
    velFinal.y = 0;
    if (posObst.y < y) {
      y -= intersecao.y;
    } else {
      y += intersecao.y;
      podePular = true;
    }
  }

  pFig->setPosition(x, y);
}
} // namespace Jogo::Entidades::Personagens
