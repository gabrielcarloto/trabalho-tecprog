#include "Entidade.h"

namespace Jogo::Entidades {
// Entidade::Entidade() ;
// Entidade::~Entidade() = default;
void Entidade::setPosicao(const int posX, const int posY) {
  x = posX;
  y = posY;
}

void Entidade::setPosicao(const sf::Vector2<int> &pos) {
  x = pos.x;
  y = pos.y;
}
} // namespace Jogo::Entidades
