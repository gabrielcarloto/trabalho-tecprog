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
} // namespace Jogo::Entidades::Personagens
