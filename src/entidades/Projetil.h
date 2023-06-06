#pragma once
#include "../Math.h"
#include "Entidade.h"
#include <SFML/System/Vector2.hpp>

namespace Jogo::Entidades {
namespace Personagens {
class Inim_Dificil;
}

class Projetil : public Entidade {
public:
  Projetil(sf::Vector2f pos, sf::Vector2f direcao, float velo,
           Personagens::Inim_Dificil *);
  ~Projetil() override;

  void executar() override { mover(); }

  void colidir(Entidade *, sf::Vector2f) override;
  bool getDeveSerRemovido() const;
  void setDeveSerRemovido();

private:
  bool penetra = false;
  bool deveSerRemovido = false;
  sf::Vector2f direcao;
  const static float distanciaMaxima;

  Personagens::Inim_Dificil *inim = nullptr;

  void mover() override;
};
} // namespace Jogo::Entidades
