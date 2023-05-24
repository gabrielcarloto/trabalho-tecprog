#include "Gerenciador_Grafico.h"
#include "entidades/Jogador.h"
#include "fases/Fase_Primeira.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

int main() {
  auto pGerenciadorGrafico =
      Jogo::Gerenciadores::Gerenciador_Grafico::getInstancia();
  Jogo::Fases::Fase_Primeira plau;
  while (pGerenciadorGrafico->verificaJanelaAberta()) {
    sf::Event event;

    while (pGerenciadorGrafico->verificarEvento(event)) {
      if (event.type == sf::Event::Closed)
        pGerenciadorGrafico->fecharJanela();
      if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape)
          pGerenciadorGrafico->fecharJanela();
    }

    pGerenciadorGrafico->limparJanela();
    pGerenciadorGrafico->desenharEnte(&plau);
    plau.executar();
    pGerenciadorGrafico->atualizaDeltaTempo();
    pGerenciadorGrafico->renderizar();
  }

  return 0;
}
