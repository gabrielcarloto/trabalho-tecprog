#pragma once
#include "Entidade.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"

namespace Jogo::Entidades::Personagens {
class Personagem : public Entidade {
public:
  Personagem(ID, const char *, sf::Vector2f, float velo);
  Personagem(ID, const char *, sf::IntRect, sf::Vector2f, float velo);

protected:
  int num_vidas = 1;
};
} // namespace Jogo::Entidades::Personagens
