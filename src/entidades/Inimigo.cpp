#include "Inimigo.h"
#include "../Math.h"
#include "../fases/Fase.h"
#include "Jogador.h"
#include "Personagem.h"
#include <stdexcept>
#include <utility>

namespace Jogo::Entidades::Personagens {
Inimigo::Inimigo(const char *path, int maldade, sf::Vector2f pos, float velo)
    : Personagem(Ente::ID::INIMIGO, path, pos, velo), nivelMaldade(maldade) {
  aterrarJogadores();
}

Inimigo::Inimigo(const char *path, sf::IntRect lim, int maldade,
                 sf::Vector2f pos, float velo)
    : Personagem(Ente::ID::INIMIGO, path, lim, pos, velo),
      nivelMaldade(maldade) {
  aterrarJogadores();
}

Inimigo::~Inimigo() { aterrarJogadores(); }
void Inimigo::morrer() {
  fase->removerEntidade(this);
  deveSerRemovido = true;
}

void Inimigo::setFase(Fases::Fase *pf) { fase = pf; }

void Inimigo::aterrarJogadores() {
  jogadores[0] = nullptr;
  jogadores[1] = nullptr;
}

void Inimigo::incluirJogador(Jogador *pJogador) {
  if (numJogadores >= 2)
    throw std::runtime_error(
        "Inimigo::incluirJogador -> Numero maximo de jogadores excedido");

  jogadores[numJogadores] = pJogador;
  numJogadores++;
}

std::pair<float, float> Inimigo::distanciaJogadores() {
  float distanciaJogador1 = 0, distanciaJogador2 = 0;

  if (!jogadores[0])
    throw std::runtime_error(
        "Inimigo::distanciaJogadores -> Nenhum jogador registrado");

  distanciaJogador1 = Math::distancia({x, y}, jogadores[0]->getPosicao());

  if (jogadores[1])
    distanciaJogador2 = Math::distancia({x, y}, jogadores[1]->getPosicao());

  return std::make_pair(distanciaJogador1, distanciaJogador2);
}

bool Inimigo::getDeveSerRemovido() const { return deveSerRemovido; }
} // namespace Jogo::Entidades::Personagens
