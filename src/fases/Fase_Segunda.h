#pragma once
#include "Fase.h"

namespace Jogo::Fases {
class Fase_Segunda : public Fase {
public:
  Fase_Segunda();
  ~Fase_Segunda() = default;

  void inicializarMapa() override;

protected:
  void criarBloco(unsigned int, unsigned int);
  void criarPassaro(unsigned int, unsigned int);
  void criarEntidadeAleatoriamente(unsigned int, unsigned int) override;

private:
  unsigned int contagemBlocos = 0;
  unsigned int contagemPassaros = 0;
};
} // namespace Jogo::Fases
