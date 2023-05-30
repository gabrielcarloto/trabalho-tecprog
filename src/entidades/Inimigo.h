#pragma once
#include "../Observer.h"
#include "Personagem.h"
#include <array>

namespace Jogo::Entidades::Personagens {
class Jogador;

class Inimigo : public Personagem, public Subject {
public:
  Inimigo(const char *, int, sf::Vector2f, float);
  Inimigo(const char *, sf::IntRect, int, sf::Vector2f, float);
  ~Inimigo();

  virtual void tomarDano() = 0;
  void incluirJogador(Jogador *);

protected:
  int numJogadores = 0;
  const int nivelMaldade;
  std::array<Jogador *, 2> jogadores;

  virtual void morrer();
  std::pair<float, float> distanciaJogadores();

private:
  void aterrarJogadores();
};
} // namespace Jogo::Entidades::Personagens
