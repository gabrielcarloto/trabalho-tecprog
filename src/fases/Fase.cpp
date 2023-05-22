#include "Fase.h"
#include "../Gerenciador_Grafico.h"

namespace Jogo::Fases {
Fase::Fase() { carregarBackground(); }

void Fase::carregarBackground() {
  inicializaSprite(CAMINHO_IMAGENS "/back.png", {0, 0});
}
} // namespace Jogo::Fases
