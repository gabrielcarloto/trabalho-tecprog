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

  // toma dano
  void operator--();

  bool getDeveSerRemovido() const;
  int getNivelMaldade() const;

protected:
  int numJogadores = 0;
  const int nivelMaldade;
  Fases::Fase *fase = nullptr;
  bool deveSerRemovido = false;
  std::array<Jogador *, 2> jogadores;
  float distanciaPerseguirJogadorX = 0, distanciaPerseguirJogadorY = 0;

  std::pair<float, float> distanciaJogadores();
  std::pair<Jogador *, float> jogadorMaisProximo();

  // retorna a direção X
  virtual float perseguirJogador(sf::Vector2f);
  virtual void moverAleatoriamente();
  void neutralizarse() override;
  void movimentar() override;

private:
  void aterrarJogadores();
};
} // namespace Jogo::Entidades::Personagens
