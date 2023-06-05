#pragma once
#include "Inimigo.h"

constexpr char CHAR_GAMBA = 'G';

namespace Jogo::Entidades::Personagens {
// inimigo médio
class Gamba : public Inimigo {
public:
  Gamba(const char *, sf::Vector2f = {0, 0}, float = 0);
  Gamba(const char *, sf::IntRect, sf::Vector2f = {0, 0}, float = 0);

  void executar() override;

private:
  bool buffVelocidadeAtivo = false;
  float velocidadeAntesDoBuff = 0;
  float tempoDoBuff = 0;

  float perseguirJogador(sf::Vector2f) override;
  void ativarBuffVelocidade();
  void desativarBuffVelocidade();
  void atualizarBuffVelocidade();
};
} // namespace Jogo::Entidades::Personagens
