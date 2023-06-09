#include "Jogo.h"
#include <iostream>
#include <stdexcept>

namespace Jogo {
Jogo::Jogo()
    : pGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia()) {
  criarJogador();
  inicializarMenuInicial();
}

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
  while (pGerenciadorGrafico->verificaJanelaAberta()) {
    atualizarEventos();
    atualizarJanela();
  }
}

void Jogo::inicializarMenuInicial() {
  menuInicial.addOpcao("Jogar primeira fase", [this]() {
    if (faseAtual)
      return;

    faseAtual = new Fases::Fase_Primeira;

    adicionarJogadoresNaFase();
    faseAtual->inicializarMapa();
  });

  menuInicial.addOpcao("Jogar segunda fase", [this]() {
    faseAtual = new Fases::Fase_Segunda;

    adicionarJogadoresNaFase();
    faseAtual->inicializarMapa();
  });

  menuInicial.addOpcao("Adicionar jogador", [this]() {
    try {
      criarJogador();
    } catch (const std::exception &) {
      std::cout << "[AVISO] Numero maximo de jogadores alcancado\n";
    }
  });

  menuInicial.addOpcao("Sair",
                       [this]() { pGerenciadorGrafico->fecharJanela(); });

  menuInicial.posicionarBotoes();
}

void Jogo::criarJogador() {
  if (listaJogadores.size() >= MAX_JOGADORES)
    throw std::runtime_error(
        "Jogo::criaJogador -> Numero maximo de jogadores atingido");

  Entidades::Personagens::Jogador *pJog = new Entidades::Personagens::Jogador(
      CAMINHO_IMAGENS "/player-idle.png", sf::IntRect(6, 10, 18, 22), {0, 0},
      130, listaJogadores.size() + 1);

  // TODO: adicionar nome pelo menu

  listaJogadores.push_back(pJog);
}

void Jogo::atualizarFase() {
  if (faseAtual && faseAtual->getExecutando()) {
    pGerenciadorGrafico->desenharEnte(faseAtual);
    faseAtual->executar();
  } else if (faseAtual) {
    Fases::Fase *proximaFase = faseAtual->getProximaFase();
    delete faseAtual;
    faseAtual = proximaFase;

    if (faseAtual) {
      adicionarJogadoresNaFase();
      faseAtual->inicializarMapa();
    } else {
      pGerenciadorGrafico->atualizarView();
    }
  }
}

void Jogo::adicionarJogadoresNaFase() {
  for (auto jog : listaJogadores) {
    faseAtual->adicionarJogador(jog);
  }
}

void Jogo::atualizarEventos() {
  while (pGerenciadorGrafico->verificarEvento(event)) {
    if (event.type == sf::Event::Closed)
      pGerenciadorGrafico->fecharJanela();
    if (event.type == sf::Event::KeyPressed)
      if (event.key.code == sf::Keyboard::Escape)
        pGerenciadorGrafico->fecharJanela();
  }
}

void Jogo::atualizarMenu() {
  pGerenciadorGrafico->desenharEnte(&menuInicial);

  menuInicial.executar();
  menuInicial.desenhar();
}

void Jogo::atualizarGerenciadorGrafico() {
  pGerenciadorGrafico->atualizaDeltaTempo();
  pGerenciadorGrafico->renderizar();
}

void Jogo::atualizarJanela() {
  pGerenciadorGrafico->limparJanela();

  atualizarMenu();
  atualizarFase();
  atualizarGerenciadorGrafico();
}
} // namespace Jogo
