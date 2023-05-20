#pragma once
#include "Entidade.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(const char *caminhoTextura, const sf::Vector2f pos = {0, 0},
          const sf::Vector2f velo = {10, 10})
      : Personagem(caminhoTextura, pos, velo) {}

  Jogador(const char *caminhoTextura, const sf::IntRect &lim,
          const sf::Vector2f pos = {0, 0}, const sf::Vector2f velo = {10, 10})
      : Personagem(caminhoTextura, lim, pos, velo) {}

  void executar() override {} // TODO: implementar
  void mover() override;
  void setEscalaFigura(float, float);
};
} // namespace Jogo::Entidades::Personagens
