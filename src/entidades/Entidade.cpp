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
} // namespace Jogo::Entidades
