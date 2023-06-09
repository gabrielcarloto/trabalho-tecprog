#include "Entidade.h"
#include <iostream>

namespace Jogo::Entidades {
// Entidade::Entidade() ;
// Entidade::~Entidade() = default;
void Entidade::setPosicao(const float posX, const float posY) {
  setPosicao({posX, posY});
}

void Entidade::setPosicao(const sf::Vector2<float> &pos) {
  x = pos.x;
  y = pos.y;

  if (posInicial.x == 0 && posInicial.y == 0)
    posInicial = pos;

  pFig->setPosition(pos);
}

void Entidade::mover() {
  float dt = pGG->getDeltaTempo();

  velFinal.y += GRAVIDADE * dt;

  x += velFinal.x * dt;
  y += velFinal.y * dt;

  pFig->setPosition(x, y);
}

sf::Vector2f Entidade::getPosicao() const { return {x, y}; }

void Entidade::colidir(float limiteX, float limiteY) {
  sf::FloatRect globalBounds = pFig->getGlobalBounds();

  if (x < 0)
    x = 0;

  if (x > limiteX - globalBounds.width)
    x = limiteX - globalBounds.width;

  if (y < 0)
    y = 0;

  if (y > limiteY - globalBounds.height)
    y = limiteY - globalBounds.height;

  setPosicao({x, y});
}

void Entidade::colidir(Entidade *pEntidade, sf::Vector2f intersecao) {
  InfoColisao info = getInfoColisao(pEntidade, intersecao);

  if (intersecao.x > intersecao.y) {
    x += intersecao.x * (info.esquerda ? -1.f : 1.f);
    velFinal.x = 0;
  } else {
    y += intersecao.y * (info.cima ? -1.f : +1.f);
    velFinal.y = 0;
  }

  pFig->setPosition(x, y);
}

Entidade::InfoColisao Entidade::getInfoColisao(Entidade *pEntidade,
                                               sf::Vector2f intersecao) {
  sf::Vector2f posEntidade = pEntidade->getPosicao();
  InfoColisao info;

  if (intersecao.x > intersecao.y) {
    info.esquerda = posEntidade.x < x;
    info.direita = !info.esquerda;
  } else {
    info.cima = posEntidade.y < y;
    info.baixo = !info.cima;
  }

  return info;
}

sf::Vector2f Entidade::getVelocidade() const { return velFinal; }
} // namespace Jogo::Entidades
