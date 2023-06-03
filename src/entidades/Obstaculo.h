#pragma once
#include "Entidade.h"

namespace Jogo::Entidades::Obstaculos {
class Obstaculo : public Entidade {
public:
  Obstaculo(bool dano, float velo, bool flut = false)
      : Entidade(Ente::ID::OBSTACULO, velo), danoso(dano), flutua(flut) {}

  virtual ~Obstaculo() = default;

  void mover() override;

protected:
  const bool danoso;
  bool flutua;
};
} // namespace Jogo::Entidades::Obstaculos
