#pragma once
#include "../Observer.h"
#include "Entidade.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Personagem.h"

constexpr char CHAR_JOGADOR = 'J';

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem, public Subject {
public:
  Jogador(const char *, sf::Vector2f = {0, 0}, float = 0, unsigned int n = 1);
  Jogador(const char *, sf::IntRect, sf::Vector2f = {0, 0}, float = 0,
          unsigned int n = 1);

  void executar() override;
  void colidir(Entidade *, sf::Vector2f) override;
  void setNome(const std::string &);
  void neutralizarse() override;

protected:
  void movimentar() override;

private:
  std::string nome;
  unsigned int pontos = 0;
  unsigned int numeroJogador;

  void operator++();
  void operator*(int);
};
} // namespace Jogo::Entidades::Personagens
