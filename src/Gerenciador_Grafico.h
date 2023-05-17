#pragma once
#include "Ente.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Jogo::Gerenciadores {
class Gerenciador_Grafico {
public:
  Gerenciador_Grafico();
  ~Gerenciador_Grafico() = default;

  void desenharEnte(Ente *); // TODO: implementar

private:
  sf::RenderWindow janela;
};
} // namespace Jogo::Gerenciadores
