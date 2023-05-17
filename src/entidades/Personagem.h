#pragma once
#include "Entidade.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"

namespace Jogo::Entidades::Personagens {
class Personagem : public Entidade {
public:
  Personagem(const char *, const sf::Vector2f &, const sf::Vector2f &);
  Personagem(const char *, const sf::IntRect &, const sf::Vector2f &,
             const sf::Vector2f &);

  virtual void mover() = 0;

protected:
  int num_vidas;
  sf::Vector2f vel;
};
} // namespace Jogo::Entidades::Personagens
