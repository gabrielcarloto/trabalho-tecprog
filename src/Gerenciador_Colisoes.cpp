#include "Gerenciador_Colisoes.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace Jogo::Gerenciadores {
Gerenciador_Colisoes::Gerenciador_Colisoes() {
  LJs[0] = nullptr;
  LJs[1] = nullptr;
}

void Gerenciador_Colisoes::gerenciar() {
  if (!LJs[0])
    throw std::runtime_error("Gerenciador_Colisoes::gerenciar -> Pelo menos um "
                             "jogador deve ser adicionado");

  for (unsigned int i = 0; i < numJogadores; i++) {
    auto jogador = LJs[i];
    auto fig = jogador->getFigura();

    for (auto obst : LOs) {
      sf::Vector2f colisao = calculaColisao(jogador, obst);

      if (checaColisao(colisao)) {
        jogador->colidir(obst, colisao);
      }
    }
  }
}

void Gerenciador_Colisoes::incluirObstaculo(
    Entidades::Obstaculos::Obstaculo *po) {
  LOs.push_back(po);
}

void Gerenciador_Colisoes::addJogador(Entidades::Personagens::Jogador *pj) {
  if (numJogadores >= 2)
    throw std::runtime_error("Gerenciador_Colisoes::addJogador -> Não é "
                             "possível ter mais que dois jogadores");

  LJs[numJogadores] = pj;
  numJogadores++;
}

sf::Vector2f Gerenciador_Colisoes::calculaColisao(Entidades::Entidade *ent1,
                                                  Entidades::Entidade *ent2) {
  auto fig1 = ent1->getFigura(), fig2 = ent2->getFigura();
  auto pos1 = fig1.getPosition(), pos2 = fig2.getPosition();
  auto tam1 = fig1.getGlobalBounds(), tam2 = fig2.getGlobalBounds();

  sf::Vector2f distanciaEntreCentros = {
      std::fabs((pos1.x + tam1.width / 2) - (pos2.x + tam2.width / 2)),
      std::fabs((pos1.y + tam1.height / 2) - (pos2.y + tam2.height / 2)),
  };

  sf::Vector2f somaMetadeRetangulo = {
      tam1.width / 2 + tam2.width / 2,
      tam1.height / 2 + tam2.height / 2,
  };

  return distanciaEntreCentros - somaMetadeRetangulo;
}

bool Gerenciador_Colisoes::checaColisao(sf::Vector2f col) {
  return col.x < 0 && col.y < 0;
}
} // namespace Jogo::Gerenciadores
