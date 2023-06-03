#pragma once
#include "Entidade.h"

namespace Jogo::Entidades::Obstaculos {
class Obstaculo : public Entidade {
public:
  Obstaculo(bool dano, float velo, bool flut = false)
      : Entidade(Ente::ID::OBSTACULO, velo), danoso(dano), flutuante(flut) {}

  virtual ~Obstaculo() = default;

  void mover() override;

protected:
  const bool danoso;
  const bool flutuante;
};
} // namespace Jogo::Entidades::Obstaculos
