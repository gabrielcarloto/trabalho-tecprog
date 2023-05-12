#pragma once
#include "Entidade.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(sf::Vector2f pos = {0, 0}, sf::Vector2f velo = {10, 10},
          float raio = 20)
      : Personagem(pos, velo, raio) {
    shape.setFillColor(sf::Color::Blue);
  }

  void executar() override {} // TODO: implementar
  void mover() override;
};
} // namespace Jogo::Entidades::Personagens
