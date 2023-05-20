#include "Gerenciador_Grafico.h"

namespace Jogo::Gerenciadores {
Gerenciador_Grafico::Gerenciador_Grafico()
    : janela(sf::VideoMode(384, 240), "Jogo") {
  janela.setFramerateLimit(60);
}

void Gerenciador_Grafico::desenharEnte(const Ente *pE) { pE->desenhar(); }
bool Gerenciador_Grafico::verificaJanelaAberta() const {
  return janela.isOpen();
}

Gerenciador_Grafico *Gerenciador_Grafico::instancia(nullptr);

Gerenciador_Grafico *Gerenciador_Grafico::getInstancia() {
  if (instancia == nullptr)
    instancia = new Gerenciador_Grafico();

  // TODO: ajeitar para as threads
  return instancia;
}
} // namespace Jogo::Gerenciadores
