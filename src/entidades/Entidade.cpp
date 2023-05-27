#include "Entidade.h"

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
} // namespace Jogo::Entidades
