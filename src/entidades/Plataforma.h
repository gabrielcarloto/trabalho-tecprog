#pragma once
#include "Jogador.h"
#include "Obstaculo.h"

constexpr char CHAR_PLATAFORMA = 'P', CHAR_PLATAFORMA_QUE_SEMPRE_CAI = '3';

namespace Jogo::Entidades::Obstaculos {
// obstáculo médio
class Plataforma : public Obstaculo {
public:
  Plataforma(const char *, sf::Vector2f = {0, 0}, bool cai = false);
  ~Plataforma() override = default;

  void executar() override;
  void colidir(Entidade *, sf::Vector2f) override;

private:
  const bool caiQuandoEncosta = false;
};
} // namespace Jogo::Entidades::Obstaculos
