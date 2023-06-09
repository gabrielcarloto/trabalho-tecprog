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
  sf::Event event;
  Menu menuInicial;

  using IteratorJogadores =
      std::list<Entidades::Personagens::Jogador *>::iterator;
};
} // namespace Jogo
