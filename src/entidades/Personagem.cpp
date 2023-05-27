#include "Personagem.h"
#include "SFML/Window/Keyboard.hpp"

namespace Jogo::Entidades::Personagens {
Personagem::Personagem(const char *caminhoTextura, sf::Vector2f pos, float velo)
    : velocidade(velo) {
  x = pos.x;
  y = pos.y;

  inicializaSprite(caminhoTextura, pos);
}

Personagem::Personagem(const char *caminhoTextura, sf::IntRect limite,
                       sf::Vector2f pos, float velo)
    : velocidade(velo) {
  x = pos.x;
  y = pos.y;

  inicializaSprite(caminhoTextura, limite, pos);
}

} // namespace Jogo::Entidades::Personagens
