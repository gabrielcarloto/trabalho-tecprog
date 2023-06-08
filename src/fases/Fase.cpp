#include "Fase.h"
#include "../Gerenciador_Grafico.h"
#include "../entidades/CaixaVenenosa.h"
#include "../entidades/Entidade.h"
#include "../entidades/Jogador.h"
#include "../entidades/Obst_Facil.h"
#include "SFML/Graphics/Rect.hpp"
#include <cctype>
#include <iostream>
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
    entidade->desenhar();
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
            criarEntidadeAleatoriamente(indiceColuna, indiceLinha);
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

  adicionarJogadoresNasEntidades();
}

void Fase::adicionarEntidadesDefault() {
  mapaEntidades['C'] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Bloco(CAMINHO_IMAGENS "/floor.png", {},
                                            true);
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

  sf::Vector2f pos = indiceParaPosicao(jogador1->getFigura().getGlobalBounds(),
                                       indiceColuna, indiceLinha);

  jogador1->setPosicao(pos);
  gerenciadorCol.addJogador(jogador1);

  if (listaJogadores.size() == 2) {
    listaJogadores[1]->setPosicao(
        {pos.x + TAMANHO_TILE + static_cast<float>(TAMANHO_TILE) * 1.5f,
         pos.y});

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

  entidade->setPosicao(indiceParaPosicao(
      entidade->getFigura().getGlobalBounds(), indiceColuna, indiceLinha));
}

void Fase::adicionarJogadoresNasEntidades() {
  for (auto entidade : listaEntidades) {
    switch (entidade->getId()) {
    case Ente::ID::INIMIGO: {
      Entidades::Personagens::Inimigo *inim =
          static_cast<Entidades::Personagens::Inimigo *>(entidade);

      for (auto jogador : listaJogadores) {
        inim->incluirJogador(jogador);
      }

      break;
    }
    case Ente::ID::OBSTACULO: {
      Entidades::Obstaculos::CaixaVenenosa *caixa =
          dynamic_cast<Entidades::Obstaculos::CaixaVenenosa *>(entidade);

      if (caixa) {
        for (auto jogador : listaJogadores) {
          caixa->incluirJogador(jogador);
        }
      }

      break;
    }
    default:
      break;
    }
  }
}

void Fase::criarGamba(unsigned int coluna, unsigned int linha) {
  Entidades::Entidade *gamba = criarEntidadeComChance(CHAR_GAMBA);

  if (gamba) {
    gamba->setPosicao(
        indiceParaPosicao(gamba->getFigura().getGlobalBounds(), coluna, linha));

    static_cast<Entidades::Personagens::Inimigo *>(gamba)->setFase(this);

    listaEntidades.push_back(gamba);
    gerenciadorCol.incluirInimigo(
        static_cast<Entidades::Personagens::Inimigo *>(gamba));
  }
}

void Fase::criarPlataforma(unsigned int coluna, unsigned int linha) {
  Entidades::Entidade *plataforma = criarEntidadeComChance(CHAR_PLATAFORMA);

  if (plataforma) {
    plataforma->setPosicao(indiceParaPosicao(
        plataforma->getFigura().getGlobalBounds(), coluna, linha));

    listaEntidades.push_back(plataforma);
    gerenciadorCol.incluirObstaculo(
        static_cast<Entidades::Obstaculos::Obstaculo *>(plataforma));
  }
}

Entidades::Entidade *Fase::criarEntidadeComChance(char caractere,
                                                  unsigned int chance) {
  if (!Uteis::chance(chance))
    return nullptr;

  auto it = mapaEntidades.find(caractere);

  if (it == mapaEntidades.end()) {
    throw std::runtime_error(std::string("Fase::criarEntidadeComChance -> "
                                         "Nenhuma entidade com caractere `") +
                             caractere + "` registrado no mapa de entidades");
  }

  Entidades::Entidade *entidade = it->second();

  return entidade;
}

sf::Vector2f Fase::indiceParaPosicao(sf::FloatRect globalBounds,
                                     unsigned int iColuna,
                                     unsigned int iLinha) {
  float iCol = static_cast<float>(iColuna), iLin = static_cast<float>(iLinha),
        tamTile = static_cast<float>(TAMANHO_TILE),
        alturaFig = globalBounds.height, larguraFig = globalBounds.width,
        posX = iCol * tamTile - larguraFig, posY = iLin * tamTile - alturaFig;

  return {posX, posY};
}
} // namespace Jogo::Fases
