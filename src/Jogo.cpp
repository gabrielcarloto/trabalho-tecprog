#include "Jogo.h"

namespace Jogo {
Jogo::Jogo()
    : pGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia()) {}

Jogo::~Jogo() {
  pGerenciadorGrafico->deletarInstancia();
  pGerenciadorGrafico = nullptr;
}

void Jogo::executar() {
  while (pGerenciadorGrafico->verificaJanelaAberta()) {
    while (pGerenciadorGrafico->verificarEvento(event)) {
      if (event.type == sf::Event::Closed)
        pGerenciadorGrafico->fecharJanela();
      if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape)
          pGerenciadorGrafico->fecharJanela();
    }

    pGerenciadorGrafico->limparJanela();
    pGerenciadorGrafico->desenharEnte(&primeiraFase);
    primeiraFase.executar();
    pGerenciadorGrafico->atualizaDeltaTempo();
    pGerenciadorGrafico->renderizar();
  }
}
} // namespace Jogo
