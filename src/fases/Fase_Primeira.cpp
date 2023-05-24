#include "Fase_Primeira.h"

namespace Jogo::Fases {
Fase_Primeira::Fase_Primeira() { inicializaMapa(); }

void Fase_Primeira::inicializaMapa() {
  adicionarEntidadesDefault();
  // TODO: adicionar ao mapaEntidades coisas específicas dessa fase
  carregarMapa(CAMINHO_FASE_PRIMEIRA "/tilemap.txt");
}
} // namespace Jogo::Fases
