#include "Fase_Primeira.h"
#include "../entidades/CaixaVenenosa.h"
#include "../entidades/Gamba.h"
#include "../entidades/Inim_Dificil.h"
#include "../entidades/Inim_Facil.h"
#include "../entidades/Obst_Facil.h"
#include "../entidades/Plataforma.h"
#include <array>
#include <cstdlib>

namespace Jogo::Fases {
Fase_Primeira::Fase_Primeira() = default;

void Fase_Primeira::inicializarMapa() {
  adicionarEntidadesDefault();

  mapaEntidades[CHAR_BLOCO] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Bloco(CAMINHO_IMAGENS "/big-crate.png",
                                            {}, false);
  };

  mapaEntidades[CHAR_BLOCO_ARRASTAVEL] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Bloco(CAMINHO_IMAGENS "/big-crate.png",
                                            {}, false, true);
  };

  mapaEntidades[CHAR_PLATAFORMA] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Plataforma(
        CAMINHO_IMAGENS "/big-crate.png", {}, Uteis::chance(10));
  };

  mapaEntidades[CHAR_CAIXA_VENENOSA] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::CaixaVenenosa(CAMINHO_IMAGENS
                                                    "/big-crate.png");
  };

  mapaEntidades[CHAR_GAMBA] = []() -> Entidades::Entidade * {
    return new Entidades::Personagens::Gamba(
        CAMINHO_IMAGENS "/oposum.png", sf::IntRect(0, 2, 32, 25), {0, 0}, 70);
  };

  mapaEntidades[CHAR_INIM_FACIL] = []() -> Entidades::Entidade * {
    return new Entidades::Personagens::Sapo(CAMINHO_IMAGENS "/frog-idle.png",
                                            sf::IntRect(0, 2, 32, 25), {0, 0},
                                            70);
  };

  // TODO: mover para a fase 2
  mapaEntidades[CHAR_INIM_DIFICIL] = []() -> Entidades::Entidade * {
    return new Entidades::Personagens::Passaro(
        CAMINHO_IMAGENS "/eagle-attack.png", sf::IntRect(122, 2, 32, 38), false,
        {0, 0}, 70);
  };

  carregarMapa(CAMINHO_FASE_PRIMEIRA "/tilemap.txt");
}

void Fase_Primeira::criarSapo(unsigned int coluna, unsigned int linha) {
  Entidades::Entidade *sapo = criarEntidadeComChance(CHAR_INIM_FACIL);

  if (sapo) {
    sapo->setPosicao(
        indiceParaPosicao(sapo->getFigura().getGlobalBounds(), coluna, linha));

    static_cast<Entidades::Personagens::Inimigo *>(sapo)->setFase(this);

    listaEntidades.push_back(sapo);
    gerenciadorCol.incluirInimigo(
        static_cast<Entidades::Personagens::Inimigo *>(sapo));
  }
}

void Fase_Primeira::criarCaixaVenenosa(unsigned int coluna,
                                       unsigned int linha) {
  Entidades::Entidade *caixa = criarEntidadeComChance(CHAR_CAIXA_VENENOSA);

  if (caixa) {
    caixa->setPosicao(
        indiceParaPosicao(caixa->getFigura().getGlobalBounds(), coluna, linha));

    listaEntidades.push_back(caixa);
    gerenciadorCol.incluirObstaculo(
        static_cast<Entidades::Obstaculos::Obstaculo *>(caixa));
  }
}

void Fase_Primeira::criarEntidadeAleatoriamente(unsigned int coluna,
                                                unsigned int linha) {
  // facilitaria muito o professor permitir std::function aqui
  switch (std::rand() % 5) {
  case 1:
    criarSapo(coluna, linha);
    break;
  case 2:
    criarGamba(coluna, linha);
    break;
  case 3:
    criarCaixaVenenosa(coluna, linha);
    break;
  case 4:
    criarPlataforma(coluna, linha);
    break;
  default:
    break;
  }
}
} // namespace Jogo::Fases
