#pragma once
#include "../Ente.h"
#include "SFML/System/Vector2.hpp"

namespace Jogo::Entidades {
class Entidade : public Ente {
public:
  Entidade() = default;
  ~Entidade() = default;

protected:
  int x, y;
};
} // namespace Jogo::Entidades
