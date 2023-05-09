#pragma once
#include "Entidade.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(sf::Vector2f pos = {0, 0}, float raio = 100) : Personagem(pos, raio) {
    shape.setFillColor(sf::Color::Blue);
  }

  void executar() override {} // TODO: implementar
};
} // namespace Jogo::Entidades::Personagens
