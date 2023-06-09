#pragma once
#include "Fase.h"

namespace Jogo::Fases {
class Fase_Primeira : public Fase {
public:
  Fase_Primeira();
  ~Fase_Primeira() = default;

  void inicializarMapa() override;
  Fase *getProximaFase() const override;

protected:
  void criarSapo(unsigned int, unsigned int);
  void criarCaixaVenenosa(unsigned int, unsigned int);
  void criarEntidadeAleatoriamente(unsigned int, unsigned int) override;

private:
  unsigned int contagemSapos = 0;
  unsigned int contagemCaixasVenenosas = 0;
};
} // namespace Jogo::Fases
