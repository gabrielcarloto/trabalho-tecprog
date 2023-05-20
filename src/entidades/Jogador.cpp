#include "Jogador.h"
#include <SFML/Graphics.hpp>

namespace Jogo::Entidades::Personagens {
void Jogador::mover() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    pFig->move(0, -vel.y);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    pFig->move(-vel.x, 0);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    pFig->move(0, vel.y);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    pFig->move(vel.x, 0);
}

void Jogador::setEscalaFigura(float fatorX, float fatorY) {
  pFig->setScale(fatorX, fatorY);
}
} // namespace Jogo::Entidades::Personagens
