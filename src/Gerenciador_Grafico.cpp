#include "Gerenciador_Grafico.h"

namespace Jogo::Gerenciadores {
Gerenciador_Grafico::Gerenciador_Grafico()
    : janela(sf::VideoMode(384, 240), "Jogo") {
  janela.setFramerateLimit(60);
}

void Gerenciador_Grafico::desenharEnte(const Ente *pE) { pE->desenhar(); }
bool Gerenciador_Grafico::janelaAberta() const { return janela.isOpen(); }
} // namespace Jogo::Gerenciadores
