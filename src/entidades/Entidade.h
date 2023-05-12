#pragma once
#include "../Ente.h"
#include "SFML/System/Vector2.hpp"

namespace Jogo::Entidades {
class Entidade : public Ente {
public:
  Entidade(sf::Vector2f &velo) : vel(velo){};
  ~Entidade();

protected:
  int x, y;
  sf::Vector2f vel;
};
} // namespace Jogo::Entidades
