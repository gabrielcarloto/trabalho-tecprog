#include "Obstaculo.h"

namespace Jogo::Entidades::Obstaculos {
void Obstaculo::mover() {
  if (flutuante) {
    float dt = pGG->getDeltaTempo();
    velFinal.y -= GRAVIDADE * dt;
  }

  Entidade::mover();
}
} // namespace Jogo::Entidades::Obstaculos
