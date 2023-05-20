#include "Personagem.h"
#include "SFML/Window/Keyboard.hpp"

namespace Jogo::Entidades::Personagens {
Personagem::Personagem(const char *caminhoTextura, const sf::Vector2f &pos,
                       const sf::Vector2f &velo) {
  x = (int)pos.x;
  y = (int)pos.y;
  vel = std::move(velo);

  inicializaSprite(caminhoTextura, pos);
}

Personagem::Personagem(const char *caminhoTextura, const sf::IntRect &limite,
                       const sf::Vector2f &pos, const sf::Vector2f &velo) {
  x = (int)pos.x;
  y = (int)pos.y;
  vel = std::move(velo);

  inicializaSprite(caminhoTextura, limite, pos);
}

} // namespace Jogo::Entidades::Personagens
