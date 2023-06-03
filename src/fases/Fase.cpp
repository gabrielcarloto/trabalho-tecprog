#include "Fase.h"
#include "../Gerenciador_Grafico.h"
#include "../entidades/Entidade.h"
#include "../entidades/Jogador.h"
#include "../entidades/Obst_Facil.h"
#include "SFML/Graphics/Rect.hpp"
#include <cctype>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

namespace Jogo::Fases {
Fase::Fase() : Ente(Ente::ID::FASE) { carregarBackground(); }

Fase::~Fase() {
  for (auto entidade : listaEntidades) {
    delete entidade;
    entidade = nullptr;
  }
}

void Fase::carregarBackground() {
  inicializaSprite(CAMINHO_IMAGENS "/back.png", {0, 0});
}

void Fase::executar() {
  for (auto entidade : listaEntidades) {
    entidade->executar();
  }

  gerenciar_colisoes();

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
      if (caractere == '.' || caractere == '\r' || caractere == '\n') {
        indiceColuna++;
        continue;
      }

      auto it = mapaEntidades.find(caractere);

      if (it != mapaEntidades.end()) {
        Entidades::Entidade *entidade = it->second();

        listaEntidades.push_back(entidade);

        switch (entidade->getId()) {
        case OBSTACULO:
          gerenciadorCol.incluirObstaculo(
              static_cast<Entidades::Obstaculos::Obstaculo *>(entidade));
          break;
        case JOGADOR:
          gerenciadorCol.addJogador(
              static_cast<Entidades::Personagens::Jogador *>(entidade));
          break;
        case Ente::ID::INIMIGO: {
          auto inim = static_cast<Entidades::Personagens::Inimigo *>(entidade);

          gerenciadorCol.incluirInimigo(inim);
          inim->setFase(this);
          break;
        }
        default:
          break;
        }

        // TODO: mover isso para o ente se possível
        // também provavelmente precisamos arrumar o posicionamento da entidade
        // criada.
        entidade->setEscalaFigura(2, 2);

        auto iCol = static_cast<float>(indiceColuna),
             iLin = static_cast<float>(indiceLinha),
             tamTile = static_cast<float>(TAMANHO_TILE),
             alturaFig = entidade->getFigura().getGlobalBounds().height;

        entidade->setPosicao(
            {iCol * tamTile - tamTile / 2, iLin * tamTile - alturaFig});
      }

      indiceColuna++;
    }

    indiceLinha++;
  });
}

void Fase::adicionarEntidadesDefault() {
  mapaEntidades['J'] = []() -> Entidades::Entidade * {
    return new Entidades::Personagens::Jogador(
        CAMINHO_IMAGENS "/player-idle.png", sf::IntRect(6, 10, 18, 22), {0, 0},
        130);
  };

  mapaEntidades['C'] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Obst_Facil(CAMINHO_IMAGENS "/floor.png");
  };
}

void Fase::removerEntidade(Entidades::Entidade *pEnt) {
  listaEntidades.remove(pEnt);
}
} // namespace Jogo::Fases
