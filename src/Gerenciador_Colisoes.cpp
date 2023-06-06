#include "Gerenciador_Colisoes.h"
#include "entidades/Obst_Facil.h"
#include "uteis.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
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

  for (IteratorObstaculos it = LOs.begin(); it != Uteis::prev(LOs.end());
       it++) {
    colidirLimitesMapa(static_cast<Entidades::Entidade *>(*it));

    for (IteratorObstaculos it2 = Uteis::next(it); it2 != LOs.end(); it2++) {
      sf::Vector2f colisao = calculaColisao(*it, *it2);

      if (checaColisao(colisao)) {
        (*it)->colidir(*it2, colisao);
        (*it2)->colidir(*it, colisao);
      }
    }
  }

  colidirLimitesMapa(
      static_cast<Entidades::Entidade *>(*Uteis::prev(LOs.end())));

  for (unsigned int i = 0; i < numJogadores; i++) {
    auto jogador = LJs[i];
    auto fig = jogador->getFigura();

    colidirLimitesMapa(static_cast<Entidades::Entidade *>(jogador));

    for (IteratorObstaculos itObst = LOs.begin(); itObst != LOs.end();
         itObst++) {
      sf::Vector2f colisao = calculaColisao(jogador, *itObst);

      if (checaColisao(colisao)) {
        jogador->colidir(*itObst, colisao);
        (*itObst)->colidir(jogador, colisao);
      }
    }

    for (IteratorInimigos itInim = LIs.begin(); itInim != LIs.end(); itInim++) {
      sf::Vector2f colisao = calculaColisao(jogador, *itInim);

      if (checaColisao(colisao)) {
        jogador->colidir(*itInim, colisao);
      }
    }

    for (IteratorProjeteis itProj = LPs.begin(); itProj != LPs.end();
         itProj++) {
      sf::Vector2f colisao = calculaColisao(jogador, *itProj);

      if (checaColisao(colisao)) {
        (*itProj)->colidir(jogador, colisao);
      }
    }
  }

  for (size_t i = 0; i < LIs.size(); i++) {
    Entidades::Personagens::Inimigo *inim = LIs[i];
    colidirLimitesMapa(static_cast<Entidades::Entidade *>(inim));

    for (IteratorObstaculos itObst = LOs.begin(); itObst != LOs.end();
         itObst++) {
      sf::Vector2f colisao = calculaColisao(inim, *itObst);

      if (checaColisao(colisao)) {
        inim->colidir(*itObst, colisao);
      }
    }

    for (size_t j = i + 1; i < LIs.size() - 1 && j < LIs.size(); j++) {
      Entidades::Personagens::Inimigo *inimJ = LIs[j];
      sf::Vector2f colisao = calculaColisao(inim, inimJ);

      if (checaColisao(colisao)) {
        inim->colidir(inimJ, colisao);
      }
    }
  }

  for (IteratorProjeteis itProj = LPs.begin(); itProj != LPs.end(); itProj++) {
    for (IteratorObstaculos itObst = LOs.begin(); itObst != LOs.end();
         itObst++) {
      sf::Vector2f colisao = calculaColisao(*itProj, *itObst);

      if (checaColisao(colisao)) {
        (*itProj)->colidir(*itObst, colisao);
      }
    }
  }

  // NOTE: (gabrielcarloto) quando o inimigo morria e era deletado, ocorria uma
  // invalidação de iteradores, crashando o programa. Agora ele é marcado para
  // ser removido após os loops.
  removerEntidadesPendentes();
}

void Gerenciador_Colisoes::colidirLimitesMapa(Entidades::Entidade *pEnt) {
  sf::FloatRect globalBounds = pEnt->getFigura().getGlobalBounds();
  sf::Vector2f pos = pEnt->getPosicao();

  if (pos.x < 0)
    pos.x = 0;

  if (pos.x > limiteMapaX - globalBounds.width)
    pos.x = limiteMapaX - globalBounds.width;

  if (pos.y < 0)
    pos.y = 0;

  if (pos.y > limiteMapaY - globalBounds.height)
    pos.y = limiteMapaY - globalBounds.height;

  pEnt->setPosicao(pos);
}

void Gerenciador_Colisoes::incluirObstaculo(
    Entidades::Obstaculos::Obstaculo *po) {
  LOs.push_back(po);
}

void Gerenciador_Colisoes::incluirInimigo(Entidades::Personagens::Inimigo *pi) {
  LIs.push_back(pi);
}

void Gerenciador_Colisoes::removerInimigo(Entidades::Personagens::Inimigo *pi) {
  auto it = std::remove(LIs.begin(), LIs.end(), pi);
  LIs.erase(it);
}

void Gerenciador_Colisoes::removerObstaculo(
    Entidades::Obstaculos::Obstaculo *po) {
  LOs.remove(po);
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

void Gerenciador_Colisoes::removerEntidadesPendentes() {
  for (auto itInimigos = LIs.begin(); itInimigos != LIs.end();) {
    if ((*itInimigos)->getDeveSerRemovido()) {
      delete *itInimigos;
      itInimigos = LIs.erase(itInimigos);
    } else {
      itInimigos++;
    }
  }

  for (auto itProjeteis = LPs.begin(); itProjeteis != LPs.end();) {
    if ((*itProjeteis)->getDeveSerRemovido()) {
      delete *itProjeteis;
      itProjeteis = LPs.erase(itProjeteis);
    } else {
      itProjeteis++;
    }
  }
}

void Gerenciador_Colisoes::setLimitesMapa(float limX, float limY) {
  limiteMapaX = limX;
  limiteMapaY = limY;
}

void Gerenciador_Colisoes::incluirProjetil(Entidades::Projetil *pProjetil) {
  LPs.push_back(pProjetil);
}
} // namespace Jogo::Gerenciadores
