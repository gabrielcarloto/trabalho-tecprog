#pragma once
#include "Entidade.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"

namespace Jogo::Entidades::Personagens {
class Personagem : public Entidade {
public:
  Personagem(const char *, sf::Vector2f, float velo);
  Personagem(const char *, sf::IntRect, sf::Vector2f, float velo);

  virtual void mover() = 0;

protected:
  int num_vidas;
  float velocidade = 0;
};
} // namespace Jogo::Entidades::Personagens
