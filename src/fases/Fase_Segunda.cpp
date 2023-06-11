#include "Fase_Segunda.h"
#include "../entidades/CaixaVenenosa.h"
#include "../entidades/Gamba.h"
#include "../entidades/Passaro.h"
#include "../entidades/Sapo.h"
#include "../entidades/Bloco.h"
#include "../entidades/Plataforma.h"

namespace Jogo::Fases {
Fase_Segunda::Fase_Segunda() = default;

void Fase_Segunda::inicializarMapa() {
  adicionarEntidadesDefault();

  mapaEntidades[CHAR_BLOCO] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Bloco(CAMINHO_IMAGENS "/big-crate.png",
                                            {}, false);
  };

  mapaEntidades[CHAR_BLOCO_ARRASTAVEL] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Bloco(CAMINHO_IMAGENS "/big-crate.png",
                                            {}, false, true);
  };

  mapaEntidades[CHAR_INIM_DIFICIL] = []() -> Entidades::Entidade * {
    return new Entidades::Personagens::Passaro(
        CAMINHO_IMAGENS "/eagle-attack.png", sf::IntRect(122, 2, 32, 38), false,
        {0, 0}, 70);
  };

  mapaEntidades[CHAR_BOSS] = []() -> Entidades::Entidade * {
    return new Entidades::Personagens::Passaro(
        CAMINHO_IMAGENS "/eagle-attack.png", sf::IntRect(122, 2, 32, 38), true,
        {0, 0}, 70);
  };

  carregarMapa(CAMINHO_FASE_SEGUNDA "/tilemap.txt");
}

void Fase_Segunda::criarBloco(unsigned int coluna, unsigned int linha) {
  if (contagemBlocos < LIMITE_ENTIDADE_ALEATORIA_POR_TIPO) {
    Entidades::Entidade *pEntidade = nullptr;

    if (Uteis::chance(75)) {
      pEntidade = criarObstaculo(CHAR_BLOCO, coluna, linha);
    } else {
      pEntidade = criarObstaculo(CHAR_BLOCO_ARRASTAVEL, coluna, linha);
    }

    if (pEntidade)
      contagemBlocos++;
  }
}

void Fase_Segunda::criarPassaro(unsigned int coluna, unsigned int linha) {
  if (contagemPassaros < LIMITE_ENTIDADE_ALEATORIA_POR_TIPO &&
      criarInimigo(CHAR_INIM_DIFICIL, coluna, linha)) {
    contagemPassaros++;
  }
}

void Fase_Segunda::criarEntidadeAleatoriamente(unsigned int coluna,
                                               unsigned int linha) {
  switch (std::rand() % 5) {
  case 1:
    criarBloco(coluna, linha);
    break;
  case 2:
    criarGamba(coluna, linha);
    break;
  case 3:
    criarPassaro(coluna, linha);
    break;
  case 4:
    criarPlataforma(coluna, linha);
    break;
  default:
    break;
  }
}
} // namespace Jogo::Fases
