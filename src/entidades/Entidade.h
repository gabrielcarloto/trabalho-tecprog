#pragma once
#include "../Ente.h"
#include <SFML/System/Vector2.hpp>

constexpr float GRAVIDADE = 981;

namespace Jogo::Entidades {
class Entidade : public Ente {
public:
  Entidade(ID idEntidade, float velo, float normal = 0)
      : Ente(idEntidade), velocidade(velo), forcaNormal(normal) {}
  virtual ~Entidade() = default;

  void setPosicao(const float x, const float y);
  void setPosicao(const sf::Vector2<float> &);

  void atualizarPosicao();

protected:
  float x, y;
  float velocidade;
  float forcaNormal;
  sf::Vector2f velFinal;

  virtual void mover() = 0;
};
} // namespace Jogo::Entidades
