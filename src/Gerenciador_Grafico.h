#pragma once
#include "Ente.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Jogo::Gerenciadores {
class Gerenciador_Grafico {
public:
  Gerenciador_Grafico();
  ~Gerenciador_Grafico() = default;

  void desenharEnte(const Ente *);
  bool janelaAberta() const;

private:
  sf::RenderWindow janela;
};
} // namespace Jogo::Gerenciadores
