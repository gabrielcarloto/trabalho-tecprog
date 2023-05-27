#pragma once
#include "Entidade.h"
#include "Obstaculo.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(const char *caminhoTextura, const sf::Vector2f pos = {0, 0},
          const sf::Vector2f velo =
              {10, 10}) // TODO: como o movimento do jogador será primariamente
                        // horizontal, não é necessário utilizar um Vector2f,
                        // apenas um float basta
      : Personagem(caminhoTextura, pos, velo) {
    id = Ente::JOGADOR;
  }

  Jogador(const char *caminhoTextura, const sf::IntRect &lim,
          const sf::Vector2f pos = {0, 0}, const sf::Vector2f velo = {10, 10})
      : Personagem(caminhoTextura, lim, pos, velo) {
    id = Ente::JOGADOR;
  }

  void executar() override;
  void mover() override;
  void colidir(int, sf::Vector2f, sf::Vector2f);

private:
  void colidirObstaculo(sf::Vector2f, sf::Vector2f);
};
} // namespace Jogo::Entidades::Personagens
