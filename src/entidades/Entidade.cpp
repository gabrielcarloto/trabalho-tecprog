#include "Entidade.h"
#include <iostream>

namespace Jogo::Entidades {
// Entidade::Entidade() ;
// Entidade::~Entidade() = default;
void Entidade::setPosicao(const float posX, const float posY) {
  x = posX;
  y = posY;

  pFig->setPosition(x, y);
}

void Entidade::setPosicao(const sf::Vector2<float> &pos) {
  x = pos.x;
  y = pos.y;

  pFig->setPosition(x, y);
}

void Entidade::atualizarPosicao() {
#ifdef DEBUG
  // dependendo da forma que o jogo está sendo debugado, pode levar muito tempo
  // entre um frame e outro, fazendo com que a velocidade seja multiplicada por
  // um valor grande, levando as entidades para fora da tela; isso mantém o
  // cálculo da velocidade de forma que isso não aconteça
  float dt = 1 / static_cast<float>(FRAMERATE_PADRAO);
#else
  float dt = pGG->getDeltaTempo();
#endif // DEBUG

  // suavidade do movimento
  velFinal.x *= 0.65f;

  mover();

  velFinal.y += GRAVIDADE * dt;
  velFinal.y -= forcaNormal * dt;

  x += velFinal.x * dt;
  y += velFinal.y * dt;

  if (x < 0)
    x = 0;

  auto globalBounds = pFig->getGlobalBounds();

  if (x > (int)LARGURA_JANELA - globalBounds.width)
    x = LARGURA_JANELA - globalBounds.width;

  if (y < 0)
    y = 0;

  if (y > (int)ALTURA_JANELA - globalBounds.height)
    y = ALTURA_JANELA - globalBounds.height;

  pFig->setPosition(x, y);
}

sf::Vector2f Entidade::getPosicao() const { return {x, y}; }
} // namespace Jogo::Entidades
