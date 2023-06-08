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

  void mover() override;
  void colidir(Entidade *, sf::Vector2f) override;

protected:
  int num_vidas = 1;
  bool podePular = true;

  virtual void movimentar() = 0;
  virtual void neutralizarse() = 0;
  void pular(float = TAMANHO_PULO);
};
} // namespace Jogo::Entidades::Personagens
