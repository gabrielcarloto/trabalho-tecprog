#pragma once
#include "Gerenciador_Grafico.h"
#include "Menu.h"
#include "SFML/Window/Event.hpp"
#include "entidades/Inimigo.h"
#include "fases/Fase_Primeira.h"
#include "fases/Fase_Segunda.h"

namespace Jogo {
class Jogo {
public:
  Jogo();
  ~Jogo();

  void executar();

private:
  Gerenciadores::Gerenciador_Grafico *pGerenciadorGrafico = nullptr;
  std::list<Entidades::Personagens::Jogador *> listaJogadores;
  Fases::Fase *faseAtual = nullptr;
  Menu menuInicial;
  sf::Event event;

  void atualizarGerenciadorGrafico();
  void adicionarJogadoresNaFase();
  void inicializarMenuInicial();
  void atualizarEventos();
  void atualizarJanela();
  void atualizarMenu();
  void atualizarFase();
  void criarJogador();

  using IteratorJogadores =
      std::list<Entidades::Personagens::Jogador *>::iterator;
};
} // namespace Jogo
