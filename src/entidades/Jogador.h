#pragma once
#include "Entidade.h"
#include "Obstaculo.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
class Jogador : public Personagem {
public:
  Jogador(const char *caminhoTextura, const sf::Vector2f pos = {0, 0},
          float velo = 0)
      : Personagem(caminhoTextura, pos, velo) {
    id = Ente::JOGADOR;
  }

  Jogador(const char *caminhoTextura, sf::IntRect lim,
          sf::Vector2f pos = {0, 0}, float velo = 0)
      : Personagem(caminhoTextura, lim, pos, velo) {
    id = Ente::JOGADOR;
  }

  void executar() override;
  void mover() override;
  void colidir(int, sf::Vector2f, sf::Vector2f);

private:
  void colidirObstaculo(sf::Vector2f, sf::Vector2f);

  const float TAMANHO_PULO = static_cast<float>(TAMANHO_TILE) * 3.5f;
  bool podePular = true;
};
} // namespace Jogo::Entidades::Personagens
