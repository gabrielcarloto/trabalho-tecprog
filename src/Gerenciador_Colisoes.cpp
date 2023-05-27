#include "Gerenciador_Colisoes.h"

namespace Jogo::Gerenciadores {
void Gerenciador_Colisoes::incluirObstaculo(
    Entidades::Obstaculos::Obstaculo *po) {
  LOs.push_back(po);
}
} // namespace Jogo::Gerenciadores
