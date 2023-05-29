#pragma once
#include "Entidade.h"

namespace Jogo::Entidades::Obstaculos {
class Obstaculo : public Entidade {
public:
  Obstaculo(bool dano, float velo)
      : Entidade(Ente::ID::OBSTACULO, velo), danoso(dano) {}
  virtual ~Obstaculo() = default;

protected:
  const bool danoso;
};
} // namespace Jogo::Entidades::Obstaculos
