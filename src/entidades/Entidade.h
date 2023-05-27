#pragma once
#include "../Ente.h"
#include "SFML/System/Vector2.hpp"

namespace Jogo::Entidades {
class Entidade : public Ente {
public:
  Entidade() = default;
  virtual ~Entidade() = default;

  void setPosicao(const float x, const float y);
  void setPosicao(const sf::Vector2<float> &);

protected:
  float x, y;
  sf::Vector2f vel;
};
} // namespace Jogo::Entidades
