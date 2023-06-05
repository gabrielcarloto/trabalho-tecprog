#pragma once
#include "Inimigo.h"

constexpr char CHAR_INIM_FACIL = 'F';

namespace Jogo::Entidades::Personagens {
class Inim_Facil : public Inimigo {
public:
  Inim_Facil(const char *, sf::Vector2f = {0, 0}, float = 0, bool = true);
  Inim_Facil(const char *, sf::IntRect, sf::Vector2f = {0, 0}, float = 0,
             bool = true);

  void executar() override;

protected:
  bool pulaAleatoriamente;

  void moverAleatoriamente() override;
  float perseguirJogador(sf::Vector2f) override;
};
} // namespace Jogo::Entidades::Personagens
