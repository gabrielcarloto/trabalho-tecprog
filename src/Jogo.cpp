#include "Jogo.h"
#include <iostream>

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

  menuInicial.addOpcao("Jogar primeira fase", [this, pJog]() {
    faseAtual = new Fases::Fase_Primeira;
    faseAtual->adicionarJogador(pJog);
    faseAtual->inicializarMapa();
  });

  menuInicial.addOpcao("Jogar segunda fase", [this, pJog]() {
    faseAtual = new Fases::Fase_Segunda;
    faseAtual->adicionarJogador(pJog);
    faseAtual->inicializarMapa();
  });

  menuInicial.addOpcao("Sair",
                       [this]() { pGerenciadorGrafico->fecharJanela(); });

  menuInicial.posicionarBotoes();

  pJog->setNome("Gabriel"); // TODO: adicionar nome pelo menu

  listaJogadores.push_back(pJog);

  while (pGerenciadorGrafico->verificaJanelaAberta()) {
    while (pGerenciadorGrafico->verificarEvento(event)) {
      if (event.type == sf::Event::Closed)
        pGerenciadorGrafico->fecharJanela();
      if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape)
          pGerenciadorGrafico->fecharJanela();
    }

    pGerenciadorGrafico->limparJanela();
    pGerenciadorGrafico->desenharEnte(&menuInicial);

    menuInicial.executar();
    menuInicial.desenhar();

    if (faseAtual && faseAtual->getExecutando()) {
      pGerenciadorGrafico->desenharEnte(faseAtual);
      faseAtual->executar();
    } else if (faseAtual) {
      delete faseAtual;
      faseAtual = nullptr;
      pGerenciadorGrafico->atualizarView();
    }

    pGerenciadorGrafico->atualizaDeltaTempo();
    pGerenciadorGrafico->renderizar();
  }
}
} // namespace Jogo
