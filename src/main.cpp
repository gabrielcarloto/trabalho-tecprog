#include "Gerenciador_Grafico.h"
#include "entidades/Jogador.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

int main() {
  auto pGerenciadorGrafico =
      Jogo::Gerenciadores::Gerenciador_Grafico::getInstancia();

  Jogo::Entidades::Personagens::Jogador teste(
      CAMINHO_IMAGENS "/player-idle.png", sf::IntRect(0, 0, 32, 32));

  teste.setEscalaFigura(2, 2);

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
    pGerenciadorGrafico->desenharEnte(&teste);
    pGerenciadorGrafico->atualizaDeltaTempo();
    pGerenciadorGrafico->renderizar();
  }

  return 0;
}
