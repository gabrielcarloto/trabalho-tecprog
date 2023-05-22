#pragma once
#include "Entidade.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(const char *caminhoTextura, const sf::Vector2f pos = {0, 0},
          const sf::Vector2f velo =
              {10, 10}) // TODO: como o movimento do jogador será primariamente
                        // horizontal, não é necessário utilizar um Vector2f,
                        // apenas um float basta
      : Personagem(caminhoTextura, pos, velo) {}

  Jogador(const char *caminhoTextura, const sf::IntRect &lim,
          const sf::Vector2f pos = {0, 0}, const sf::Vector2f velo = {10, 10})
      : Personagem(caminhoTextura, lim, pos, velo) {}

  void executar() override;
  void mover() override;
};
} // namespace Jogo::Entidades::Personagens
