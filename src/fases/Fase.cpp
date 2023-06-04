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
Fase::Fase() : Ente(Ente::ID::FASE) {
  carregarBackground();
  listaJogadores.reserve(2);
}

Fase::~Fase() {
  for (size_t i = 0; i < listaJogadores.size(); i++) {
    listaEntidades.remove(listaJogadores[i]);
  }

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

  unsigned int indiceLinha = 0, indiceColuna = 0;
  Uteis::lerArquivo(
      path, [&indiceLinha, &indiceColuna, this](std::string &linha) {
        indiceColuna = 0;

        for (const char caractere : linha) {
          if (caractere == '.' || caractere == '\r' || caractere == '\n') {
            indiceColuna++;
            continue;
          }

          if (caractere == CHAR_JOGADOR) {
            posicionarJogadores(indiceColuna, indiceLinha);
            indiceColuna++;
            continue;
          }

          auto it = mapaEntidades.find(caractere);

          if (it != mapaEntidades.end()) {
            posicionarEntidade(indiceColuna, indiceLinha, (*it).second());
          }

          indiceColuna++;
        }

        indiceLinha++;
      });

  gerenciadorCol.setLimitesMapa(
      static_cast<float>((indiceColuna - 1) * TAMANHO_TILE),
      static_cast<float>((indiceLinha - 1) * TAMANHO_TILE));
}

void Fase::adicionarEntidadesDefault() {
  mapaEntidades['C'] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Obst_Facil(CAMINHO_IMAGENS "/floor.png");
  };
}

void Fase::removerEntidade(Entidades::Entidade *pEnt) {
  listaEntidades.remove(pEnt);
}

void Fase::adicionarEntidade(Entidades::Projetil *pProjetil) {
  listaEntidades.push_back(static_cast<Entidades::Entidade *>(pProjetil));
  gerenciadorCol.incluirProjetil(pProjetil);
}

void Fase::adicionarJogador(Entidades::Personagens::Jogador *pJogador) {
  if (listaJogadores.size() >= 2)
    throw std::runtime_error(
        "Fase::adicionarJogador -> Numero maximo de jogadores atingido");

  listaJogadores.push_back(pJogador);
  listaEntidades.push_back(pJogador);
}

void Fase::posicionarJogadores(unsigned int indiceColuna,
                               unsigned int indiceLinha) {
  if (listaJogadores.size() == 0)
    throw std::runtime_error(
        "Fase::posicionarJogadores -> Nenhum jogador adicionado");

  Entidades::Personagens::Jogador *jogador1 = listaJogadores[0];

  sf::FloatRect globalBounds = jogador1->getFigura().getGlobalBounds();

  float iCol = static_cast<float>(indiceColuna),
        iLin = static_cast<float>(indiceLinha),
        tamTile = static_cast<float>(TAMANHO_TILE),
        alturaFig = globalBounds.height, larguraFig = globalBounds.width,
        posX = iCol * tamTile - larguraFig, posY = iLin * tamTile - alturaFig;

  jogador1->setPosicao({posX, posY});
  gerenciadorCol.addJogador(jogador1);

  if (listaJogadores.size() == 2) {
    listaJogadores[1]->setPosicao({posX + TAMANHO_TILE, posY});
    gerenciadorCol.addJogador(listaJogadores[1]);
  }
}

void Fase::posicionarEntidade(unsigned int indiceColuna,
                              unsigned int indiceLinha,
                              Entidades::Entidade *entidade) {
  listaEntidades.push_back(entidade);

  switch (entidade->getId()) {
  case OBSTACULO:
    gerenciadorCol.incluirObstaculo(
        static_cast<Entidades::Obstaculos::Obstaculo *>(entidade));
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

  sf::FloatRect globalBounds = entidade->getFigura().getGlobalBounds();

  float iCol = static_cast<float>(indiceColuna),
        iLin = static_cast<float>(indiceLinha),
        tamTile = static_cast<float>(TAMANHO_TILE),
        alturaFig = globalBounds.height, larguraFig = globalBounds.width;

  entidade->setPosicao(
      {iCol * tamTile - larguraFig, iLin * tamTile - alturaFig});
}
} // namespace Jogo::Fases
