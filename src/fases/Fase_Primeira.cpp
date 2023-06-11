#include "Fase_Primeira.h"
#include "../entidades/CaixaVenenosa.h"
#include "../entidades/Gamba.h"
#include "../entidades/Passaro.h"
#include "../entidades/Sapo.h"
#include "../entidades/Bloco.h"
#include "../entidades/Plataforma.h"
#include "Fase_Segunda.h"
#include <cstdlib>

namespace Jogo::Fases {
Fase_Primeira::Fase_Primeira() = default;

void Fase_Primeira::inicializarMapa() {
  adicionarEntidadesDefault();

  mapaEntidades[CHAR_CAIXA_VENENOSA] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::CaixaVenenosa(CAMINHO_IMAGENS
                                                    "/big-crate.png");
  };

  mapaEntidades[CHAR_INIM_FACIL] = []() -> Entidades::Entidade * {
    return new Entidades::Personagens::Sapo(
        CAMINHO_IMAGENS "/frog-idle.png", sf::IntRect(0, 2, 32, 25), {0, 0}, 70,
        true, static_cast<float>(1 + std::rand() % 5));
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

Fase *Fase_Primeira::getProximaFase() const {
  return jogadorFinalizouFase ? new Fase_Segunda : nullptr;
}
} // namespace Jogo::Fases
