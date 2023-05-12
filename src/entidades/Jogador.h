#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "SFML/Window/Keyboard.hpp"

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(sf::Vector2f pos = {0, 0}, sf::Vector2f velo = {10, 10},
          float raio = 20)
      : Personagem(pos, velo, raio) {
    shape.setFillColor(sf::Color::Blue);
  }

  void executar() override {} // TODO: implementar

  void mover() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      shape.move(0, -vel.y);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      shape.move(-vel.x, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      shape.move(0, vel.y);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      shape.move(vel.x, 0);
  }
};
} // namespace Jogo::Entidades::Personagens
