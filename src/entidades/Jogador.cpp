#include "Jogador.h"
#include <SFML/Graphics.hpp>

namespace Jogo::Entidades::Personagens {
void Jogador::mover() {
  auto isKeyPressed = sf::Keyboard::isKeyPressed;

  if (isKeyPressed(sf::Keyboard::W))
    y -= vel.y;
  if (isKeyPressed(sf::Keyboard::A))
    x -= vel.x;
  if (isKeyPressed(sf::Keyboard::S))
    y += vel.y;
  if (isKeyPressed(sf::Keyboard::D))
    x += vel.x;

  if (x < 0)
    x = 0;

  auto globalBounds = pFig->getGlobalBounds();

  if (x > (int)LARGURA_JANELA - globalBounds.width)
    x = LARGURA_JANELA - globalBounds.width;

  if (y < 0)
    y = 0;

  if (y > (int)ALTURA_JANELA - globalBounds.height)
    y = ALTURA_JANELA - globalBounds.height;

  pFig->setPosition(x, y);
}

void Jogador::executar() { mover(); }
} // namespace Jogo::Entidades::Personagens
