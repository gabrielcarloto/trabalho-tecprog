#pragma once
#include "../Ente.h"
#include "SFML/System/Vector2.hpp"

namespace Jogo::Entidades {
class Entidade : public Ente {
public:
  Entidade() = default;
  ~Entidade() = default;

  void setPosicao(const int x, const int y);
  void setPosicao(const sf::Vector2<int> &);

protected:
  int x, y;
  sf::Vector2f vel;
};
} // namespace Jogo::Entidades
