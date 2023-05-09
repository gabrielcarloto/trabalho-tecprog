#pragma once
#include "../Ente.h"

namespace Jogo::Entidades {
class Entidade : public Ente {
public:
  Entidade();
  ~Entidade();

protected:
  int x, y;
};
} // namespace Jogo::Entidades
