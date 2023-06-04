#pragma once
#include "Entidade.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(const char *, sf::Vector2f = {0, 0}, float = 0);
  Jogador(const char *, sf::IntRect, sf::Vector2f = {0, 0}, float = 0);

  void executar() override;
  void colidir(Entidade *, sf::Vector2f) override;
  void neutralizarse();

protected:
  void movimentar() override;

private:
  unsigned int pontos = 0;

  void colidirObstaculo(Obstaculos::Obstaculo *, sf::Vector2f);
  void colidirInimigo(Inimigo *, sf::Vector2f);

  void operator++();
};
} // namespace Jogo::Entidades::Personagens
