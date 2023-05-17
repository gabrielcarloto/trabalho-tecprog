#pragma once
#include "Entidade.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(const char *caminhoTextura, const sf::Vector2f pos = {0, 0},
          const sf::Vector2f velo = {10, 10})
      : Personagem(caminhoTextura, pos, velo) {}

  void executar() override {} // TODO: implementar
  void mover() override;
};
} // namespace Jogo::Entidades::Personagens
