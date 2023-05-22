#include "Fase.h"
#include "../Gerenciador_Grafico.h"
#include "../entidades/Entidade.h"
#include "../uteis.h"
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

template <class E, typename... Args>
void Fase::carregarMapa(const char *path, Args... args) {
  static_assert(std::is_base_of_v<Entidades::Entidade, E>);

  unsigned int indiceLinha = 0;
  Uteis::lerArquivo(path, [&args..., this, &indiceLinha](auto &linha) {
    unsigned int indiceEntidade = 0;

    for (auto caractere : linha) {
      if (caractere == '0')
        continue;

      E *entidade = new E(std::forward(args...));

      // TODO: adicionar no gerenciador de obstaculos com switch/case usando os
      // IDs

      listaEntidades.push_back(entidade);
      entidade->setPosicao(
          {indiceLinha * TAMANHO_TILE, indiceEntidade * TAMANHO_TILE});

      indiceEntidade++;
    }

    indiceLinha++;
  });
}

} // namespace Jogo::Fases
