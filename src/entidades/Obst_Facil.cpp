#include "Obst_Facil.h"
#include <cstdlib>

namespace Jogo::Entidades::Obstaculos {
Obst_Facil::Obst_Facil(const char *path, sf::Vector2f pos, bool flut,
                       bool podeCairQuandoPisa)
    : Obstaculo(false, 0, flut), caiQuandoJogadorPisa(podeCairQuandoPisa) {
  inicializaSprite(path, pos);
}

void Obst_Facil::executar() { mover(); }

void Obst_Facil::colidir(Personagens::Jogador *) {
  if (caiQuandoJogadorPisa)
    flutua = false;
}
} // namespace Jogo::Entidades::Obstaculos
