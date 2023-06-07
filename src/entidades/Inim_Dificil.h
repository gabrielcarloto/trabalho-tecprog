#pragma once
#include "../uteis.h"
#include "Inimigo.h"
#include "Projetil.h"

constexpr char CHAR_INIM_DIFICIL = 'D';

namespace Jogo::Entidades::Personagens {
class Passaro : public Inimigo {
public:
  Passaro(const char *, bool, sf::Vector2f = {0, 0}, float = 0);
  Passaro(const char *, sf::IntRect, bool, sf::Vector2f = {0, 0}, float = 0);
  ~Passaro();

  void executar() override;
  void mover() override;
  void deletarProjetil();

protected:
  float perseguirJogador(sf::Vector2f) override;

private:
  Projetil *projetil = nullptr;

  void arremessar(sf::Vector2f);
  void construtora(bool);
};
} // namespace Jogo::Entidades::Personagens