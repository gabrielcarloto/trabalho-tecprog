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
  num_vidas = maldade / 10;
}

Inimigo::Inimigo(const char *path, sf::IntRect lim, int maldade,
                 sf::Vector2f pos, float velo)
    : Personagem(Ente::ID::INIMIGO, path, lim, pos, velo),
      nivelMaldade(maldade) {
  aterrarJogadores();
  num_vidas = maldade / 10;
}

Inimigo::~Inimigo() { aterrarJogadores(); }
void Inimigo::operator--() { tomarDano(); }

void Inimigo::neutralizarse() {
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

void Inimigo::tomarDano() {
  num_vidas--;

  if (num_vidas <= 0)
    neutralizarse();
}

void Inimigo::colidir(Entidade *pEnt, sf::Vector2f intersecao) {
  auto posObst = pEnt->getPosicao();

  if (intersecao.x > intersecao.y) {
    x += intersecao.x * (posObst.x < x ? -1.f : 1.f);
    velFinal.x = 0;
  } else {
    velFinal.y = 0;
    if (posObst.y < y) {
      y -= intersecao.y;
    } else {
      y += intersecao.y;
      podePular = true;
    }
  }

  pFig->setPosition(x, y);
}

std::pair<Jogador *, float> Inimigo::jogadorMaisProximo() {
  auto distJogadores = distanciaJogadores();

  if (!jogadores[1] || distJogadores.first < distJogadores.second)
    return std::make_pair(jogadores[0], distJogadores.first);

  return std::make_pair(jogadores[1], distJogadores.second);
}

void Inimigo::perseguirJogador(sf::Vector2f posJogador) {
  float direcao = posJogador.x > x ? 1 : -1;
  velFinal.x += velocidade * direcao;
}

void Inimigo::moverAleatoriamente() {
  float direcaoAleatoria = Uteis::chance(5) ? 1 : -1;
  float direcao = direcaoAleatoria * (velFinal.x < 0 ? 1.f : -1.f);
  velFinal.x += velocidade / 2 * direcao;
}

void Inimigo::movimentar() {
  auto jogadorProximo = jogadorMaisProximo();
  auto posJogadorProximo = jogadorProximo.first->getPosicao();

  if (std::abs(posJogadorProximo.y - y) <= distanciaPerseguirJogadorY &&
      jogadorProximo.second <= distanciaPerseguirJogadorX) {
    return perseguirJogador(posJogadorProximo);
  }

  moverAleatoriamente();
}

int Inimigo::getNivelMaldade() const { return nivelMaldade; }
} // namespace Jogo::Entidades::Personagens
