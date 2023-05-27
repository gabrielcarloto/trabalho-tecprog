#pragma once
#include "entidades/Jogador.h"
#include "entidades/Obstaculo.h"
#include <array>
#include <list>

namespace Jogo::Gerenciadores {
class Gerenciador_Colisoes {
public:
  Gerenciador_Colisoes();
  ~Gerenciador_Colisoes() = default;

  void gerenciar();

  void incluirObstaculo(Entidades::Obstaculos::Obstaculo *);
  // void incluirInimigo(Inimigo *);
  void addJogador(Entidades::Personagens::Jogador *);

private:
  // std::vector<Inimigo *> LIs;
  std::list<Entidades::Obstaculos::Obstaculo *> LOs;
  std::array<Entidades::Personagens::Jogador *, 2> LJs;

  unsigned int numJogadores = 0;

  sf::Vector2f calculaColisao(Entidades::Entidade *, Entidades::Entidade *);
  bool checaColisao(sf::Vector2f);
};
} // namespace Jogo::Gerenciadores
