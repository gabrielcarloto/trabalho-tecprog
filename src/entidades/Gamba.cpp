#include "Gamba.h"
#include "../uteis.h"

constexpr int MALDADE_PADRAO_MEDIO = 20, BUFF_VELOCIDADE = 50,
              VELOCIDADE_PADRAO = 70;
constexpr float DISTANCIA_X_PERSEGUIR_JOGADOR = TAMANHO_TILE * 5,
                DISTANCIA_Y_PERSEGUIR_JOGADOR =
                    static_cast<float>(TAMANHO_TILE) / 2;

namespace Jogo::Entidades::Personagens {
Gamba::Gamba(const char *path, sf::Vector2f pos, float velo)
    : Inimigo(path, MALDADE_PADRAO_MEDIO, pos, velo) {
  distanciaPerseguirJogadorX = DISTANCIA_X_PERSEGUIR_JOGADOR;
  distanciaPerseguirJogadorY = DISTANCIA_Y_PERSEGUIR_JOGADOR;
}

Gamba::Gamba(const char *path, sf::IntRect lim, sf::Vector2f pos, float velo)
    : Inimigo(path, lim, MALDADE_PADRAO_MEDIO, pos, velo) {
  distanciaPerseguirJogadorX = DISTANCIA_X_PERSEGUIR_JOGADOR;
  distanciaPerseguirJogadorY = DISTANCIA_Y_PERSEGUIR_JOGADOR;
}

void Gamba::executar() {
  mover();
  atualizarBuffVelocidade();
}

float Gamba::perseguirJogador(sf::Vector2f posJogador) {
  float direcao = Inimigo::perseguirJogador(posJogador);

  if (!buffVelocidadeAtivo && Uteis::chance(1))
    ativarBuffVelocidade();

  return direcao;
}

void Gamba::ativarBuffVelocidade() {
  buffVelocidadeAtivo = true;
  velocidadeAntesDoBuff = velocidade;
  velocidade += static_cast<float>(rand() % BUFF_VELOCIDADE);
}

void Gamba::atualizarBuffVelocidade() {
  tempoDoBuff += pGG->getDeltaTempo();

  if (tempoDoBuff > 3)
    desativarBuffVelocidade();
}

void Gamba::desativarBuffVelocidade() {
  buffVelocidadeAtivo = false;
  velocidade =
      velocidadeAntesDoBuff > 0 ? velocidadeAntesDoBuff : VELOCIDADE_PADRAO;
}
} // namespace Jogo::Entidades::Personagens
