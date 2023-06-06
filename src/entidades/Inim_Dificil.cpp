#include "Inim_Dificil.h"
#include "../fases/Fase.h"

constexpr int MALDADE_PADRAO_DIFICIL = 10, MALDADE_PADRAO_DIFICIL_BOSS = 30;
constexpr float DISTANCIA_X_PERSEGUIR_JOGADOR = TAMANHO_TILE * 5,
                DISTANCIA_Y_PERSEGUIR_JOGADOR =
                    static_cast<float>(TAMANHO_TILE) * 1.5f;

namespace Jogo::Entidades::Personagens {
Passaro::Passaro(const char *path, bool boss, sf::Vector2f pos, float velo)
    : Inimigo(path, boss ? MALDADE_PADRAO_DIFICIL_BOSS : MALDADE_PADRAO_DIFICIL,
              pos, velo) {
  construtora(boss);
}

Passaro::Passaro(const char *path, sf::IntRect lim, bool boss, sf::Vector2f pos,
                 float velo)
    : Inimigo(path, lim,
              boss ? MALDADE_PADRAO_DIFICIL_BOSS : MALDADE_PADRAO_DIFICIL, pos,
              velo) {
  construtora(boss);
}

void Passaro::construtora(bool boss) {
  distanciaPerseguirJogadorX = DISTANCIA_X_PERSEGUIR_JOGADOR;
  distanciaPerseguirJogadorY = DISTANCIA_Y_PERSEGUIR_JOGADOR;

  if (boss) {
    setEscalaFigura(4, 4);

    distanciaPerseguirJogadorX *= 2;
    distanciaPerseguirJogadorY *= 2;
  }
}

Passaro::~Passaro() {
  if (projetil)
    projetil->setDeveSerRemovido();

  deletarProjetil();
}

void Passaro::executar() { mover(); }

void Passaro::mover() {
  velFinal.y -= GRAVIDADE * pGG->getDeltaTempo();
  Personagem::mover();
}

float Passaro::perseguirJogador(sf::Vector2f posJogador) {
  float direcaoX = Inimigo::perseguirJogador(posJogador);
  float direcaoY = posJogador.y > y ? 1 : -1;

  velFinal.y += velocidade / 10 * direcaoY;

  if (!projetil)
    arremessar({direcaoX, direcaoY});

  return direcaoX;
}

void Passaro::arremessar(sf::Vector2f direcao) {
  projetil = new Projetil({x, y}, direcao, velocidade * 2, this);
  fase->adicionarEntidade(projetil);
}

void Passaro::deletarProjetil() {
  fase->removerEntidade(projetil);
  projetil = nullptr;
}
} // namespace Jogo::Entidades::Personagens
