#include "Chao.h"

namespace Jogo::Entidades::Obstaculos {
Chao::Chao(const char *path, sf::Vector2f pos)
    : Obstaculo(false, 0, GRAVIDADE) {
  inicializaSprite(path, pos);
  x = pos.x;
  y = pos.y;
}

void Chao::executar() { atualizarPosicao(); }
} // namespace Jogo::Entidades::Obstaculos
