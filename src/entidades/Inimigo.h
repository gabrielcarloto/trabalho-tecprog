#pragma once
#include "Personagem.h"
#include <array>

namespace Jogo::Fases {
class Fase;
}

namespace Jogo::Entidades::Personagens {
class Jogador;

class Inimigo : public Personagem {
public:
  Inimigo(const char *, int, sf::Vector2f, float);
  Inimigo(const char *, sf::IntRect, int, sf::Vector2f, float);
  ~Inimigo();

  virtual void tomarDano() = 0;
  void incluirJogador(Jogador *);
  void setFase(Fases::Fase *);

  // toma dano
  void operator--();

  bool getDeveSerRemovido() const;

protected:
  int numJogadores = 0;
  const int nivelMaldade;
  Fases::Fase *fase = nullptr;
  bool deveSerRemovido = false;
  std::array<Jogador *, 2> jogadores;

  virtual void neutralizarse();
  std::pair<float, float> distanciaJogadores();

private:
  void aterrarJogadores();
};
} // namespace Jogo::Entidades::Personagens
