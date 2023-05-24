#include "Chao.h"

namespace Jogo::Entidades {
Chao::Chao(const char *path, sf::Vector2f pos) {
  inicializaSprite(path, pos);
  x = pos.x;
  y = pos.y;

  id = Ente::CHAO;
}

void Chao::executar() {} // TODO: fazer o método executar
} // namespace Jogo::Entidades
