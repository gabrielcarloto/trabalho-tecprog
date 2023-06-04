#pragma once
#include "../uteis.h"
#include "Inimigo.h"
#include "Projetil.h"

constexpr char CHAR_INIM_DIFICIL = 'D';

namespace Jogo::Entidades::Personagens {
class Inim_Dificil : public Inimigo {
public:
  Inim_Dificil(const char *, sf::Vector2f = {0, 0}, float = 0);
  Inim_Dificil(const char *, sf::IntRect, sf::Vector2f = {0, 0}, float = 0);
  ~Inim_Dificil();

  void executar() override;
  void mover() override;
  void deletarProjetil();

protected:
  void perseguirJogador(sf::Vector2f) override;

private:
  Projetil *projetil = nullptr;
  void arremessar(sf::Vector2f);
};
} // namespace Jogo::Entidades::Personagens
