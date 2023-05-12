#pragma once
#include "Entidade.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"

namespace Jogo::Entidades::Personagens {
class Personagem : public Entidade {
public:
  Personagem(sf::Vector2f &pos, float raio) : shape(raio) {
    x = (int)pos.x;
    y = (int)pos.y;

    shape.setPosition(pos);
  }

  const sf::CircleShape &getShape() { return shape; }

protected:
  int num_vidas;
  sf::CircleShape shape;
};
} // namespace Jogo::Entidades::Personagens
