#pragma once
#include "Entidade.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(const char *, const sf::Vector2f = {0, 0}, float = 0);
  Jogador(const char *, sf::IntRect, sf::Vector2f = {0, 0}, float = 0);

  void executar() override;
  void mover() override;
  void colidir(Entidade *, sf::Vector2f) override;

private:
  void colidirObstaculo(Obstaculos::Obstaculo *, sf::Vector2f);
  void colidirInimigo(Inimigo *, sf::Vector2f);
};
} // namespace Jogo::Entidades::Personagens
