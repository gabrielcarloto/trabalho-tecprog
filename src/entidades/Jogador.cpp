#include "Jogador.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdexcept>
#include <string>

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

void Jogador::colidir(int idOutro, sf::Vector2f posOutro,
                      sf::Vector2f intersecao) {
  switch (idOutro) {
  case Ente::OBSTACULO:
    return colidirObstaculo(posOutro, intersecao);
  default:
    throw std::runtime_error("Jogador::colidir -> ID " + std::to_string(id) +
                             " nao colidindo");
  }
}

void Jogador::colidirObstaculo(sf::Vector2f posObst, sf::Vector2f intersecao) {
  if (intersecao.x > intersecao.y) {
    x += intersecao.x * (posObst.x < x ? -1.f : 1.f);
  } else {
    y += intersecao.y * (posObst.y < y ? -1.f : 1.f);
  }

  pFig->setPosition(x, y);
}
} // namespace Jogo::Entidades::Personagens
