#pragma once
#include "../Ente.h"
#include <SFML/System/Vector2.hpp>

constexpr float GRAVIDADE = 981;

namespace Jogo::Entidades {
class Entidade : public Ente {
public:
  Entidade(ID idEntidade, float velo) : Ente(idEntidade), velocidade(velo) {}
  virtual ~Entidade() = default;

  struct InfoColisao;

  void setPosicao(const float x, const float y);
  void setPosicao(const sf::Vector2<float> &);
  sf::Vector2f getPosicao() const;

  virtual void mover();
  virtual void colidir(Entidade *, sf::Vector2f);

protected:
  float x, y;
  float velocidade;
  sf::Vector2f velFinal;
  sf::Vector2f posInicial;

  InfoColisao getInfoColisao(Entidade *, sf::Vector2f);

public:
  struct InfoColisao {
    bool cima = false;
    bool baixo = false;
    bool esquerda = false;
    bool direita = false;
  };
};
} // namespace Jogo::Entidades
