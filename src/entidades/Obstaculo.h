#pragma once
#include "Entidade.h"

namespace Jogo::Entidades::Obstaculos {
class Obstaculo : public Entidade {
public:
  Obstaculo(bool dano) : Entidade(Ente::ID::OBSTACULO), danoso(dano) {}
  virtual ~Obstaculo() = default;

protected:
  const bool danoso;
};
} // namespace Jogo::Entidades::Obstaculos
