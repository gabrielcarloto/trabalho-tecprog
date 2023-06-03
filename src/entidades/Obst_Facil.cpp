#include "Obst_Facil.h"

namespace Jogo::Entidades::Obstaculos {
Obst_Facil::Obst_Facil(const char *path, sf::Vector2f pos, bool flut)
    : Obstaculo(false, 0, flut) {
  inicializaSprite(path, pos);
}

void Obst_Facil::executar() { mover(); }
} // namespace Jogo::Entidades::Obstaculos
