#pragma once
#include "../Observer.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
class Inimigo : public Personagem, public Subject {
public:
  Inimigo(const char *, int, sf::Vector2f, float);
  Inimigo(const char *, sf::IntRect, int, sf::Vector2f, float);

  virtual void tomarDano() = 0;

protected:
  const int nivelMaldade;

  virtual void morrer();
};
} // namespace Jogo::Entidades::Personagens
