#include "Fase.h"
#include "../Gerenciador_Grafico.h"
#include "../entidades/Chao.h"
#include "../entidades/Entidade.h"
#include "../entidades/Jogador.h"
#include "SFML/Graphics/Rect.hpp"
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

void Fase::carregarMapa(const char *path) {
  if (!path)
    throw std::runtime_error("Fase::carregarMapa -> `path` não pode ser nulo");

  unsigned int indiceLinha = 0;
  Uteis::lerArquivo(path, [&indiceLinha, this](std::string &linha) {
    unsigned int indiceColuna = 0;

    for (const char caractere : linha) {
      if (caractere == '\r' || caractere == '\n') {
        indiceColuna++;
        continue;
      }

      auto it = mapaEntidades.find(caractere);

      if (it != mapaEntidades.end()) {
        Entidades::Entidade *entidade = it->second();

        // TODO: adicionar ao gerenciador de colisões também
        listaEntidades.push_back(entidade);

        // TODO: mover isso para o ente se possível
        // também provavelmente precisamos arrumar o posicionamento da entidade
        // criada.
        entidade->setEscalaFigura(2, 2);
        entidade->setPosicao(
            {static_cast<int>(indiceColuna * TAMANHO_TILE - TAMANHO_TILE / 2),
             static_cast<int>(indiceLinha * TAMANHO_TILE - TAMANHO_TILE / 2)});
      }

      indiceColuna++;
    }

    indiceLinha++;
  });
}

void Fase::adicionarEntidadesDefault() {
  mapaEntidades['J'] = []() -> Entidades::Entidade * {
    return new Entidades::Personagens::Jogador(
        CAMINHO_IMAGENS "/player-idle.png", sf::IntRect(0, 0, 32, 32));
  };

  mapaEntidades['C'] = []() -> Entidades::Entidade * {
    return new Entidades::Chao(CAMINHO_IMAGENS "/floor.png");
  };
}
} // namespace Jogo::Fases
