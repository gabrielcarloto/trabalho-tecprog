#include "Jogador.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdexcept>
#include <string>

namespace Jogo::Entidades::Personagens {
Jogador::Jogador(const char *caminhoTextura, const sf::Vector2f pos, float velo)
    : Personagem(Ente::ID::JOGADOR, caminhoTextura, pos, velo) {}

Jogador::Jogador(const char *caminhoTextura, sf::IntRect lim, sf::Vector2f pos,
                 float velo)
    : Personagem(Ente::ID::JOGADOR, caminhoTextura, lim, pos, velo) {}

void Jogador::mover() {
  auto isKeyPressed = sf::Keyboard::isKeyPressed;

  if (isKeyPressed(sf::Keyboard::A))
    velFinal.x -= velocidade;
  if (isKeyPressed(sf::Keyboard::D))
    velFinal.x += velocidade;

  // TODO: quem sabe adicionar tamanho do pulo em função do tempo que o espaço
  // ficou pressionado
  if (podePular && isKeyPressed(sf::Keyboard::Space)) {
    pular();
  }
}

void Jogador::executar() { atualizarPosicao(); }

void Jogador::colidir(Entidade *outra, sf::Vector2f intersecao) {
  switch (outra->getId()) {
  case Ente::ID::OBSTACULO:
    return colidirObstaculo(static_cast<Obstaculos::Obstaculo *>(outra),
                            intersecao);
  case Ente::ID::INIMIGO:
    return colidirInimigo(static_cast<Inimigo *>(outra), intersecao);
  default:
    throw std::runtime_error("Jogador::colidir -> ID " + std::to_string(id) +
                             " nao colidindo");
  }
}

void Jogador::colidirObstaculo(Obstaculos::Obstaculo *obst,
                               sf::Vector2f intersecao) {
  auto posObst = obst->getFigura().getPosition();
  // TODO: lidar com obstáculos danosos

  if (intersecao.x > intersecao.y) {
    x += intersecao.x * (posObst.x < x ? -1.f : 1.f);
    velFinal.x = 0;
  } else {
    velFinal.y = 0;
    if (posObst.y < y) {
      y -= intersecao.y;
    } else {
      y += intersecao.y;
      podePular = true;
    }
  }

  pFig->setPosition(x, y);
}

void Jogador::colidirInimigo(Inimigo *inim, sf::Vector2f intersecao) {
  auto posInim = inim->getFigura().getPosition();

  if (intersecao.x > intersecao.y) {
    x += intersecao.x * (posInim.x < x ? -1.f : 1.f);
    velFinal.x = 0;
  } else {
    velFinal.y = 0;
    if (posInim.y < y) {
      y -= intersecao.y;
    } else {
      y += intersecao.y;
      pular(static_cast<float>(TAMANHO_TILE) / 2);
      inim->tomarDano();
    }
  }

  pFig->setPosition(x, y);
}

} // namespace Jogo::Entidades::Personagens
