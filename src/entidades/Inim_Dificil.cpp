#include "Inim_Dificil.h"
#include "../fases/Fase.h"

constexpr int MALDADE_PADRAO_DIFICIL = 10;
constexpr float DISTANCIA_X_PERSEGUIR_JOGADOR = TAMANHO_TILE * 5,
                DISTANCIA_Y_PERSEGUIR_JOGADOR =
                    static_cast<float>(TAMANHO_TILE) * 1.5f;

namespace Jogo::Entidades::Personagens {
Inim_Dificil::Inim_Dificil(const char *path, sf::Vector2f pos, float velo)
    : Inimigo(path, MALDADE_PADRAO_DIFICIL, pos, velo) {
  distanciaPerseguirJogadorX = DISTANCIA_X_PERSEGUIR_JOGADOR;
  distanciaPerseguirJogadorY = DISTANCIA_Y_PERSEGUIR_JOGADOR;
}

Inim_Dificil::Inim_Dificil(const char *path, sf::IntRect lim, sf::Vector2f pos,
                           float velo)
    : Inimigo(path, lim, MALDADE_PADRAO_DIFICIL, pos, velo) {
  distanciaPerseguirJogadorX = DISTANCIA_X_PERSEGUIR_JOGADOR;
  distanciaPerseguirJogadorY = DISTANCIA_Y_PERSEGUIR_JOGADOR;
}

Inim_Dificil::~Inim_Dificil() {
  if (projetil)
    projetil->setDeveSerRemovido();

  deletarProjetil();
}

void Inim_Dificil::executar() { mover(); }

void Inim_Dificil::mover() {
  velFinal.y -= GRAVIDADE * pGG->getDeltaTempo();
  Personagem::mover();
}

void Inim_Dificil::perseguirJogador(sf::Vector2f posJogador) {
  Inimigo::perseguirJogador(posJogador);

  float direcaoY = posJogador.y > y ? 1 : -1;
  float direcaoX = posJogador.x > x ? 1 : -1;

  velFinal.y += velocidade / 10 * direcaoY;

  if (!projetil)
    arremessar({direcaoX, direcaoY});
}

void Inim_Dificil::arremessar(sf::Vector2f direcao) {
  projetil = new Projetil({x, y}, direcao, velocidade * 2, this);
  fase->adicionarEntidade(projetil);
}

void Inim_Dificil::deletarProjetil() {
  fase->removerEntidade(projetil);
  projetil = nullptr;
}
} // namespace Jogo::Entidades::Personagens
