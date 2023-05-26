#include "Fase_Primeira.h"
#include "../entidades/Obst_Facil.h"

namespace Jogo::Fases {
Fase_Primeira::Fase_Primeira() { inicializaMapa(); }

void Fase_Primeira::inicializaMapa() {
  adicionarEntidadesDefault();

  mapaEntidades['1'] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Obst_Facil(CAMINHO_IMAGENS
                                                 "/big-crate.png");
  };

  carregarMapa(CAMINHO_FASE_PRIMEIRA "/tilemap.txt");
}
} // namespace Jogo::Fases
