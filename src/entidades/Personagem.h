#pragma once
#include "Entidade.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"

constexpr float TAMANHO_PULO = static_cast<float>(TAMANHO_TILE) * 3.5f;

namespace Jogo::Entidades::Personagens {
class Personagem : public Entidade {
public:
  Personagem(ID, const char *, sf::Vector2f, float velo);
  Personagem(ID, const char *, sf::IntRect, sf::Vector2f, float velo);

  virtual void colidir(Entidade *, sf::Vector2f) = 0;

  void mover() override;

protected:
  int num_vidas = 1;
  bool podePular = true;

  void pular(float = TAMANHO_PULO);
  virtual void movimentar() = 0;
};
} // namespace Jogo::Entidades::Personagens
