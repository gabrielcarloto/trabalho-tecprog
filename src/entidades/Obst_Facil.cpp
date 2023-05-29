#include "Obst_Facil.h"

namespace Jogo::Entidades::Obstaculos {
Obst_Facil::Obst_Facil(const char *path, sf::Vector2f pos)
    : Obstaculo(false, 0, GRAVIDADE) {
  inicializaSprite(path, pos);
}

void Obst_Facil::executar() { atualizarPosicao(); }
} // namespace Jogo::Entidades::Obstaculos
