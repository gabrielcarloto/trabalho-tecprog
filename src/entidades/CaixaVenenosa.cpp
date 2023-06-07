#include "CaixaVenenosa.h"
#include "../Math.h"
#include "Obstaculo.h"
#include "SFML/Config.hpp"

constexpr float TEMPO_MAXIMO_ATE_JOGADOR_MORRER_ENVENENADO = 3,
                FATOR_DIMINUICAO_TEMPO_AO_COLIDIR = 1.01f;

constexpr sf::Uint8 VENENO_R = 0, VENENO_G = 255, VENENO_B = 0, VENENO_A = 75;

namespace Jogo::Entidades::Obstaculos {
CaixaVenenosa::CaixaVenenosa(const char *caminhoTextura, sf::Vector2f pos,
                             bool flut, float raio)
    : Obstaculo(false, flut), raioVeneno(raio), veneno(raio) {
  inicializaSprite(caminhoTextura, pos);

  jogadores[0] = nullptr;
  jogadores[1] = nullptr;

  tempoJogadoresEnvenenados[0] = 0;
  tempoJogadoresEnvenenados[1] = 0;

  veneno.setFillColor({VENENO_R, VENENO_G, VENENO_B, VENENO_A});
}

void CaixaVenenosa::executar() {
  mover();
  danificarJogadores();
}

void CaixaVenenosa::danificarJogadores() {
  auto distancias = distanciaJogadores();

  for (size_t i = 0; i < MAX_JOGADORES; i++) {
    if (!jogadores[i])
      continue;

    if (distancias[i] > raioVeneno) {
      tempoJogadoresEnvenenados[i] = 0;
      continue;
    }

    tempoJogadoresEnvenenados[i] += pGG->getDeltaTempo();

    // clang-format off
    if (tempoJogadoresEnvenenados[i] > TEMPO_MAXIMO_ATE_JOGADOR_MORRER_ENVENENADO) {
      // clang-format on
      jogadores[i]->neutralizarse();
    }
  }
}

void CaixaVenenosa::colidir(Entidade *pEnt, sf::Vector2f intersecao) {
  if (pEnt->getId() != Ente::ID::JOGADOR) {
    return Entidade::colidir(pEnt, intersecao);
  }

  for (size_t i = 0; i < MAX_JOGADORES; i++) {
    if (pEnt == jogadores[i]) {
      tempoJogadoresEnvenenados[i] *= FATOR_DIMINUICAO_TEMPO_AO_COLIDIR;
    }
  }
}

void CaixaVenenosa::mover() {
  Obstaculo::mover();

  sf::FloatRect globalBoundsCaixa = pFig->getGlobalBounds();

  veneno.setPosition({x - raioVeneno + globalBoundsCaixa.width / 2,
                      y - raioVeneno + globalBoundsCaixa.height / 2});
}

void CaixaVenenosa::setPosicao(const sf::Vector2f &pos) {
  Entidade::setPosicao(pos);

  sf::FloatRect globalBoundsCaixa = pFig->getGlobalBounds();

  veneno.setPosition({pos.x - raioVeneno + globalBoundsCaixa.width / 2,
                      pos.y - raioVeneno + globalBoundsCaixa.height / 2});
}

void CaixaVenenosa::incluirJogador(Personagens::Jogador *pJogador) {
  if (numJogadores >= MAX_JOGADORES)
    throw std::runtime_error(
        "CaixaVenenosa::incluirJogador -> Numero maximo de jogadores excedido");

  jogadores[numJogadores] = pJogador;
  numJogadores++;
}

std::array<float, MAX_JOGADORES> CaixaVenenosa::distanciaJogadores() {
  std::array<float, MAX_JOGADORES> distancias;

  if (!jogadores[0])
    throw std::runtime_error(
        "CaixaVenenosa::distanciaJogadores -> Nenhum jogador registrado");

  distancias[1] = 0;

  for (size_t i = 0; i < MAX_JOGADORES; i++) {
    if (jogadores[i]) {
      distancias[i] = Math::distancia({x, y}, jogadores[i]->getPosicao());
    }
  }

  return distancias;
}

void CaixaVenenosa::desenhar() {
  Ente::desenhar();
  pGG->desenharFigura(veneno);
}
} // namespace Jogo::Entidades::Obstaculos
