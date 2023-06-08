#include "Jogo.h"

namespace Jogo {
Jogo::Jogo()
    : pGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia()) {}

Jogo::~Jogo() {
  pGerenciadorGrafico->deletarInstancia();
  pGerenciadorGrafico = nullptr;

  for (IteratorJogadores it = listaJogadores.begin();
       it != listaJogadores.end(); it++) {
    delete *it;
    *it = nullptr;
  }
}

void Jogo::executar() {
  Entidades::Personagens::Jogador *pJog = new Entidades::Personagens::Jogador(
      CAMINHO_IMAGENS "/player-idle.png", sf::IntRect(6, 10, 18, 22), {0, 0},
      130);

  pJog->setNome("Gabriel"); // TODO: adicionar nome pelo menu

  listaJogadores.push_back(pJog);
  primeiraFase.adicionarJogador(pJog);
  primeiraFase.inicializarMapa();

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

    if (primeiraFase.getExecutando()) {
      primeiraFase.executar();
    } else {
      // pGerenciadorGrafico->fecharJanela();
    }

    pGerenciadorGrafico->atualizaDeltaTempo();
    pGerenciadorGrafico->renderizar();
  }
}
} // namespace Jogo
