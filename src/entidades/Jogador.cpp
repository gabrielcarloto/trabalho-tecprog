#include "Jogador.h"
#include <SFML/Graphics.hpp>

namespace Jogo::Entidades::Personagens {
void Jogador::mover() {
  auto isKeyPressed = sf::Keyboard::isKeyPressed;

  if (isKeyPressed(sf::Keyboard::W))
    y -= static_cast<int>(vel.y);
  if (isKeyPressed(sf::Keyboard::A))
    x -= static_cast<int>(vel.x);
  if (isKeyPressed(sf::Keyboard::S))
    y += static_cast<int>(vel.y);
  if (isKeyPressed(sf::Keyboard::D))
    x += static_cast<int>(vel.x);

  pFig->setPosition(static_cast<float>(x), static_cast<float>(y));

  if (x < 0)
    x = 0;

  if (x > (int)LARGURA_JANELA - (int)TAMANHO_TILE)
    x = LARGURA_JANELA - TAMANHO_TILE;

  if (y < 0)
    y = 0;

  if (y > (int)ALTURA_JANELA - (int)TAMANHO_TILE)
    y = ALTURA_JANELA - TAMANHO_TILE;
}

void Jogador::executar() { mover(); }
} // namespace Jogo::Entidades::Personagens
