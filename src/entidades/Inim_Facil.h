#pragma once
#include "Inimigo.h"

constexpr char CHAR_INIM_FACIL = 'F';

namespace Jogo::Entidades::Personagens {
class Inim_Facil : public Inimigo {
public:
  Inim_Facil(const char *, sf::Vector2f = {0, 0}, float = 0);
  Inim_Facil(const char *, sf::IntRect, sf::Vector2f = {0, 0}, float = 0);

  void executar() override;
  void mover() override;
  void tomarDano() override;

  void colidir(Entidade *, sf::Vector2f) override;

private:
  std::pair<Jogador *, float> jogadorMaisProximo();
  void moverAleatoriamente();
  void perseguirJogador(sf::Vector2f);
};
} // namespace Jogo::Entidades::Personagens
