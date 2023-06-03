#pragma once
#include "entidades/Inimigo.h"
#include "entidades/Jogador.h"
#include "entidades/Obstaculo.h"
#include <array>
#include <list>
#include <vector>

namespace Jogo::Gerenciadores {
class Gerenciador_Colisoes {
public:
  Gerenciador_Colisoes();
  ~Gerenciador_Colisoes() = default;

  void gerenciar();

  void incluirObstaculo(Entidades::Obstaculos::Obstaculo *);
  void removerObstaculo(Entidades::Obstaculos::Obstaculo *);
  void incluirInimigo(Entidades::Personagens::Inimigo *);
  void removerInimigo(Entidades::Personagens::Inimigo *);
  void addJogador(Entidades::Personagens::Jogador *);

private:
  std::array<Entidades::Personagens::Jogador *, 2> LJs;
  std::vector<Entidades::Personagens::Inimigo *> LIs;
  std::list<Entidades::Obstaculos::Obstaculo *> LOs;

  unsigned int numJogadores = 0;

  sf::Vector2f calculaColisao(Entidades::Entidade *, Entidades::Entidade *);
  void colidirLimitesMapa(Entidades::Entidade *);
  bool checaColisao(sf::Vector2f);

  void removerEntidades();

  using IteratorObjetos =
      std::list<Entidades::Obstaculos::Obstaculo *>::iterator;

  using IteratorInimigos =
      std::vector<Entidades::Personagens::Inimigo *>::iterator;
};
} // namespace Jogo::Gerenciadores
