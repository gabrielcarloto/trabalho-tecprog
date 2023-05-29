#pragma once
#include "Gerenciador_Grafico.h"
#include "SFML/Window/Event.hpp"
#include "fases/Fase_Primeira.h"

namespace Jogo {
class Jogo {
public:
  Jogo();
  ~Jogo();

  void executar();

private:
  Gerenciadores::Gerenciador_Grafico *pGerenciadorGrafico = nullptr;
  Fases::Fase_Primeira primeiraFase;
  sf::Event event;
};
} // namespace Jogo
