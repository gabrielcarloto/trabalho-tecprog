#include "Fase.h"
#include "../Gerenciador_Grafico.h"
#include "../entidades/Entidade.h"
#include <type_traits>
#include <utility>

namespace Jogo::Fases {
Fase::Fase() {
  id = FASE;
  carregarBackground();
}

void Fase::carregarBackground() {
  inicializaSprite(CAMINHO_IMAGENS "/back.png", {0, 0});
}

void Fase::executar() {
  for (auto entidade : listaEntidades) {
    pGG->desenharEnte(entidade);
  }
}
} // namespace Jogo::Fases
