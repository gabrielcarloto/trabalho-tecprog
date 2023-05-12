#include "Jogador.h"
#include <SFML/Graphics.hpp>

namespace Jogo::Entidades::Personagens {
void Jogador::mover() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    shape.move(0, -vel.y);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    shape.move(-vel.x, 0);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    shape.move(0, vel.y);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    shape.move(vel.x, 0);
}
} // namespace Jogo::Entidades::Personagens
