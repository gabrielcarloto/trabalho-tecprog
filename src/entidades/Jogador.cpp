#include "Jogador.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdexcept>
#include <string>

constexpr float GRAVIDADE = 981;

namespace Jogo::Entidades::Personagens {
Jogador::Jogador(const char *caminhoTextura, const sf::Vector2f pos, float velo)
    : Personagem(Ente::ID::JOGADOR, caminhoTextura, pos, velo) {}

Jogador::Jogador(const char *caminhoTextura, sf::IntRect lim, sf::Vector2f pos,
                 float velo)
    : Personagem(Ente::ID::JOGADOR, caminhoTextura, lim, pos, velo) {}

void Jogador::mover() {
  float dt = pGG->getDeltaTempo();

  auto isKeyPressed = sf::Keyboard::isKeyPressed;

  // suavidade do movimento
  vel.x *= 0.65f;

  if (isKeyPressed(sf::Keyboard::A))
    vel.x -= velocidade;
  if (isKeyPressed(sf::Keyboard::D))
    vel.x += velocidade;

  // TODO: quem sabe adicionar tamanho do pulo em função do tempo que o espaço
  // ficou pressionado
  if (podePular && isKeyPressed(sf::Keyboard::Space)) {
    podePular = false;
    vel.y -= std::sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
  }

  vel.y += GRAVIDADE * dt;

  x += vel.x * dt;
  y += vel.y * dt;

  if (x < 0)
    x = 0;

  auto globalBounds = pFig->getGlobalBounds();

  if (x > (int)LARGURA_JANELA - globalBounds.width)
    x = LARGURA_JANELA - globalBounds.width;

  if (y < 0)
    y = 0;

  if (y > (int)ALTURA_JANELA - globalBounds.height)
    y = ALTURA_JANELA - globalBounds.height;

  pFig->setPosition(x, y);
}

void Jogador::executar() { mover(); }

void Jogador::colidir(Entidade *outra, sf::Vector2f intersecao) {
  switch (outra->getId()) {
  case Ente::OBSTACULO:
    return colidirObstaculo(static_cast<Obstaculos::Obstaculo *>(outra),
                            intersecao);
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
    vel.x = 0;
  } else {
    vel.y = 0;
    if (posObst.y < y) {
      y -= intersecao.y;
    } else {
      y += intersecao.y;
      podePular = true;
    }
  }

  pFig->setPosition(x, y);
}
} // namespace Jogo::Entidades::Personagens
