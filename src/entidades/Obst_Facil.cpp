#include "Obst_Facil.h"
#include <cstdlib>

namespace Jogo::Entidades::Obstaculos {
Bloco::Bloco(const char *path, sf::Vector2f pos, bool flut, bool arrasta)
    : Obstaculo(false, 0, flut), arrastavel(arrasta) {
  inicializaSprite(path, pos);
}

void Bloco::executar() { mover(); }

void Bloco::colidir(Entidade *pEnt, sf::Vector2f intersecao) {
  switch (pEnt->getId()) {
  case Ente::ID::JOGADOR: {
    if (arrastavel) {
      InfoColisao info = getInfoColisao(pEnt, intersecao);
      if (info.esquerda || info.direita)
        x += intersecao.x * (info.esquerda ? -1.f : 1.f);
    }

    break;
  }
  case Ente::ID::OBSTACULO: {
    Bloco *pBloco = dynamic_cast<Bloco *>(pEnt);

    // BUG: por algum raio de motivo algumas caixas passam pelo chão como se não
    // fosse nada e o chão do canto inferior esquedo do tilemap precisou ser
    // removido porque era teleportado para a posição do jogador
    if (!pBloco || !pBloco->arrastavel)
      Entidade::colidir(pEnt, intersecao);
    break;
  }
  default:
    break;
  }
}
} // namespace Jogo::Entidades::Obstaculos
