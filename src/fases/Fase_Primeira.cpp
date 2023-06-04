#include "Fase_Primeira.h"
#include "../entidades/Inim_Dificil.h"
#include "../entidades/Inim_Facil.h"
#include "../entidades/Obst_Facil.h"

namespace Jogo::Fases {
Fase_Primeira::Fase_Primeira() { inicializaMapa(); }

void Fase_Primeira::inicializaMapa() {
  adicionarEntidadesDefault();

  mapaEntidades['1'] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Obst_Facil(
        CAMINHO_IMAGENS "/big-crate.png", {}, true);
  };

  mapaEntidades['P'] = []() -> Entidades::Entidade * {
    return new Entidades::Obstaculos::Obst_Facil(
        CAMINHO_IMAGENS "/big-crate.png", {}, true, Uteis::chance(10));
  };

  mapaEntidades[CHAR_INIM_FACIL] = []() -> Entidades::Entidade * {
    return new Entidades::Personagens::Inim_Facil(
        CAMINHO_IMAGENS "/oposum.png", sf::IntRect(0, 2, 32, 25), {0, 0}, 70);
  };

  // TODO: mover para a fase 2
  mapaEntidades[CHAR_INIM_DIFICIL] = []() -> Entidades::Entidade * {
    return new Entidades::Personagens::Inim_Dificil(
        CAMINHO_IMAGENS "/eagle-attack.png", sf::IntRect(122, 2, 32, 38),
        {0, 0}, 70);
  };

  carregarMapa(CAMINHO_FASE_PRIMEIRA "/tilemap.txt");
}
} // namespace Jogo::Fases
