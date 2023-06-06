#include "Personagem.h"
#include "SFML/Window/Keyboard.hpp"
#include <cmath>

namespace Jogo::Entidades::Personagens {
Personagem::Personagem(ID idPersonagem, const char *caminhoTextura,
                       sf::Vector2f pos, float velo)
    : Entidade(idPersonagem, velo) {
  x = pos.x;
  y = pos.y;

  inicializaSprite(caminhoTextura, pos);
}

Personagem::Personagem(ID idPersonagem, const char *caminhoTextura,
                       sf::IntRect limite, sf::Vector2f pos, float velo)
    : Entidade(idPersonagem, velo) {
  x = pos.x;
  y = pos.y;

  inicializaSprite(caminhoTextura, limite, pos);
}

void Personagem::pular(float altura) {
  podePular = false;
  velFinal.y -= std::sqrt(2.0f * GRAVIDADE * altura);
}

void Personagem::mover() {
  // suavidade do movimento
  velFinal.x *= 0.65f;

  movimentar();
  Entidade::mover();
}

void Personagem::colidir(Entidade *pEnt, sf::Vector2f intersecao) {
  Entidade::colidir(pEnt, intersecao);
  InfoColisao info = getInfoColisao(pEnt, intersecao);

  if (info.baixo)
    podePular = true;
}
} // namespace Jogo::Entidades::Personagens
