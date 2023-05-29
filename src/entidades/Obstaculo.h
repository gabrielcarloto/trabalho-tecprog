#pragma once
#include "Entidade.h"

namespace Jogo::Entidades::Obstaculos {
class Obstaculo : public Entidade {
public:
  Obstaculo(bool dano, float velo, float normal)
      : Entidade(Ente::ID::OBSTACULO, velo, normal), danoso(dano) {}
  virtual ~Obstaculo() = default;

protected:
  const bool danoso;
};
} // namespace Jogo::Entidades::Obstaculos
