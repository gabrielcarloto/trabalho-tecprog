#pragma once
#include "Entidade.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Personagem.h"

constexpr char CHAR_JOGADOR = 'J';

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(const char *, sf::Vector2f = {0, 0}, float = 0);
  Jogador(const char *, sf::IntRect, sf::Vector2f = {0, 0}, float = 0);

  void executar() override;
  void colidir(Entidade *, sf::Vector2f) override;
  void setNome(const std::string &);
  void neutralizarse();

protected:
  void movimentar() override;

private:
  std::string nome;
  unsigned int pontos = 0;

  void colidirObstaculo(Obstaculos::Obstaculo *, sf::Vector2f);
  void colidirInimigo(Inimigo *, sf::Vector2f);

  void operator++();
  void operator*(int);
};
} // namespace Jogo::Entidades::Personagens
