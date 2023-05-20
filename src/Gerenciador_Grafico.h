#pragma once
#include "Ente.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Jogo::Gerenciadores {
class Gerenciador_Grafico {
public:
  ~Gerenciador_Grafico() = default;

  void desenharEnte(const Ente *);
  bool verificaJanelaAberta() const;

  static Gerenciador_Grafico *getInstancia();

private:
  Gerenciador_Grafico();
  sf::RenderWindow janela;

  static Gerenciador_Grafico *instancia;
};
} // namespace Jogo::Gerenciadores
