#pragma once
#include "Inimigo.h"

constexpr char CHAR_INIM_FACIL = 'F';
constexpr float FATOR_PULO_PADRAO = 3;

namespace Jogo::Entidades::Personagens {
class Inim_Facil : public Inimigo {
public:
  Inim_Facil(const char *, sf::Vector2f = {0, 0}, float = 0, bool = true,
             float = FATOR_PULO_PADRAO);
  Inim_Facil(const char *, sf::IntRect, sf::Vector2f = {0, 0}, float = 0,
             bool = true, float = FATOR_PULO_PADRAO);

  void executar() override;

protected:
  bool pulaAleatoriamente;
  float fatorPulo;

  void moverAleatoriamente() override;
  float perseguirJogador(sf::Vector2f) override;
};
} // namespace Jogo::Entidades::Personagens
