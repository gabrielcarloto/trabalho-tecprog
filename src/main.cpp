#include "Gerenciador_Grafico.h"
#include "entidades/Jogador.h"
#include <SFML/Graphics.hpp>

#define CAMINHO_ASSETS "./assets"
#define CAMINHO_FONTES CAMINHO_ASSETS "/fonts"
#define CAMINHO_IMAGENS CAMINHO_ASSETS "/images"

int main() {
  auto pGerenciadorGrafico =
      Jogo::Gerenciadores::Gerenciador_Grafico::getInstancia();

  Jogo::Entidades::Personagens::Jogador teste(CAMINHO_IMAGENS
                                              "/player-idle.png");

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
    pGerenciadorGrafico->renderizar();
  }

  return 0;
}
