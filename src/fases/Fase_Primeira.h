#pragma once
#include "Fase.h"

namespace Jogo::Fases {
class Fase_Primeira : public Fase {
public:
  Fase_Primeira();
  ~Fase_Primeira() = default;

  void inicializarMapa() override;
};
} // namespace Jogo::Fases
