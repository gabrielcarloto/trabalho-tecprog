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

  virtual void tomarDano();
  void incluirJogador(Jogador *);
  void setFase(Fases::Fase *);
  virtual void colidir(Entidade *, sf::Vector2f);

  // toma dano
  void operator--();

  bool getDeveSerRemovido() const;

protected:
  int numJogadores = 0;
  const int nivelMaldade;
  Fases::Fase *fase = nullptr;
  bool deveSerRemovido = false;
  std::array<Jogador *, 2> jogadores;
  float distanciaPerseguirJogadorX = 0, distanciaPerseguirJogadorY = 0;

  virtual void neutralizarse();
  std::pair<float, float> distanciaJogadores();
  std::pair<Jogador *, float> jogadorMaisProximo();
  virtual void moverAleatoriamente();
  virtual void perseguirJogador(sf::Vector2f);
  virtual void movimentar();

private:
  void aterrarJogadores();
};
} // namespace Jogo::Entidades::Personagens
