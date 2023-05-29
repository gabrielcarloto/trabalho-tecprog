#pragma once
#include "Entidade.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Personagem.h"

constexpr float TAMANHO_PULO = static_cast<float>(TAMANHO_TILE) * 3.5f;

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(const char *, const sf::Vector2f = {0, 0}, float = 0);
  Jogador(const char *, sf::IntRect, sf::Vector2f = {0, 0}, float = 0);

  void executar() override;
  void mover() override;
  void colidir(Entidade *, sf::Vector2f);

private:
  void colidirObstaculo(Obstaculos::Obstaculo *, sf::Vector2f);
  void colidirInimigo(Inimigo *, sf::Vector2f);

  void pular(float = TAMANHO_PULO);

  bool podePular = true;
};
} // namespace Jogo::Entidades::Personagens
