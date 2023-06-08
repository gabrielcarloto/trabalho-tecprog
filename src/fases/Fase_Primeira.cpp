#include "Fase_Primeira.h"
#include "../entidades/CaixaVenenosa.h"
#include "../entidades/Gamba.h"
#include "../entidades/Inim_Dificil.h"
#include "../entidades/Inim_Facil.h"
#include "../entidades/Obst_Facil.h"
#include "../entidades/Plataforma.h"
#include <array>
#include <cstdlib>
#include <functional>

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
  if (contagemSapos < LIMITE_ENTIDADE_ALEATORIA_POR_TIPO &&
      criarInimigo(CHAR_INIM_FACIL, coluna, linha)) {
    contagemSapos++;
  }
}

void Fase_Primeira::criarCaixaVenenosa(unsigned int coluna,
                                       unsigned int linha) {
  if (contagemCaixasVenenosas < LIMITE_ENTIDADE_ALEATORIA_POR_TIPO &&
      criarObstaculo(CHAR_CAIXA_VENENOSA, coluna, linha)) {
    contagemCaixasVenenosas++;
  }
}

void Fase_Primeira::criarEntidadeAleatoriamente(unsigned int coluna,
                                                unsigned int linha) {
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
