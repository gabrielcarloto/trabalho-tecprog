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
  float dt = 0.016;

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
} // namespace Jogo::Entidades
