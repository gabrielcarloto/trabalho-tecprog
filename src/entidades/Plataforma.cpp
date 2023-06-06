#include "Plataforma.h"

namespace Jogo::Entidades::Obstaculos {
Plataforma::Plataforma(const char *path, sf::Vector2f pos,
                       bool podeCairQuandoPisa)
    : Obstaculo(false, 0, true), caiQuandoJogadorPisa(podeCairQuandoPisa) {
  inicializaSprite(path, pos);
}

void Plataforma::executar() { mover(); }

void Plataforma::colidir(Entidade *pEnt, sf::Vector2f) {
  if (pEnt->getId() == Ente::ID::JOGADOR && caiQuandoJogadorPisa)
    flutua = false;
}
} // namespace Jogo::Entidades::Obstaculos
