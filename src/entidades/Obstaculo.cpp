#include "Obstaculo.h"

namespace Jogo::Entidades::Obstaculos {
void Obstaculo::mover() {
  if (flutua) {
    float dt = pGG->getDeltaTempo();
    velFinal.y -= GRAVIDADE * dt;
  }

  Entidade::mover();
}
} // namespace Jogo::Entidades::Obstaculos
