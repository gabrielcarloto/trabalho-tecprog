#include "Projetil.h"
#include "Entidade.h"
#include "Passaro.h"
#include "Jogador.h"

namespace Jogo::Entidades {
Projetil::Projetil(sf::Vector2f pos, sf::Vector2f dir, float velo,
                   Personagens::Passaro *pInim)
    : Entidade(Ente::ID::PROJETIL, velo), penetra(Uteis::chance(30)),
      direcao(dir), inim(pInim) {
  inicializaSprite(CAMINHO_IMAGENS "/projetil.png", pos);
  setPosicao(pos);
}

Projetil::~Projetil() {
  if (inim)
    inim->deletarProjetil();
}

const float Projetil::distanciaMaxima(
    Math::distancia({0, 0}, {static_cast<float>(LARGURA_JANELA) / 2,
                             static_cast<float>(ALTURA_JANELA) / 2}));

void Projetil::mover() {
  velFinal.x = direcao.x * velocidade;
  velFinal.y = direcao.y * velocidade;

  Entidade::mover();

  if (Math::distancia({x, y}, posInicial) > distanciaMaxima)
    deveSerRemovido = true;
}

bool Projetil::getDeveSerRemovido() const { return deveSerRemovido; }

void Projetil::colidir(Entidade *pEnt, sf::Vector2f) {
  switch (pEnt->getId()) {
  case Ente::JOGADOR: {
    Personagens::Jogador *pJog = static_cast<Personagens::Jogador *>(pEnt);
    pJog->neutralizarse();
    deveSerRemovido = true;
    break;
  }
  default: {
    if (!penetra)
      deveSerRemovido = true;
    break;
  }
  }
}

void Projetil::setDeveSerRemovido(bool aterrarInimigo) {
  deveSerRemovido = true;

  if (aterrarInimigo)
    inim = nullptr;
}
} // namespace Jogo::Entidades
