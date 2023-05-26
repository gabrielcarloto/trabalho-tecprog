#include "Obst_Facil.h"

namespace Jogo::Entidades::Obstaculos {
Obst_Facil::Obst_Facil(const char *path, sf::Vector2f pos) : Obstaculo(false) {
  inicializaSprite(path, pos);
}
} // namespace Jogo::Entidades::Obstaculos
