#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
Personagem::Personagem(const char *caminhoTextura, const sf::Vector2f &pos,
                       const sf::Vector2f &velo)
    : vel(velo) {
  x = (int)pos.x;
  y = (int)pos.y;

  inicializaSprite(caminhoTextura, pos);
}

Personagem::Personagem(const char *caminhoTextura, const sf::IntRect &limite,
                       const sf::Vector2f &pos, const sf::Vector2f &velo)
    : vel(velo) {
  x = (int)pos.x;
  y = (int)pos.y;

  inicializaSprite(caminhoTextura, limite, pos);
}

} // namespace Jogo::Entidades::Personagens
