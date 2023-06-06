#include "Jogador.h"
#include "SFML/System/Sleep.hpp"
#include "SFML/System/Time.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>

namespace Jogo::Entidades::Personagens {
Jogador::Jogador(const char *caminhoTextura, const sf::Vector2f pos, float velo,
                 unsigned int n)
    : Personagem(Ente::ID::JOGADOR, caminhoTextura, pos, velo),
      numeroJogador(n) {}

Jogador::Jogador(const char *caminhoTextura, sf::IntRect lim, sf::Vector2f pos,
                 float velo, unsigned int n)
    : Personagem(Ente::ID::JOGADOR, caminhoTextura, lim, pos, velo),
      numeroJogador(n) {}

void Jogador::movimentar() {
  auto isKeyPressed = sf::Keyboard::isKeyPressed;

  if (numeroJogador == 1) {
    if (isKeyPressed(sf::Keyboard::A))
      velFinal.x -= velocidade;
    if (isKeyPressed(sf::Keyboard::D))
      velFinal.x += velocidade;

    if (podePular && isKeyPressed(sf::Keyboard::Space)) {
      pular();
    }
  } else {
    if (isKeyPressed(sf::Keyboard::Left))
      velFinal.x -= velocidade;
    if (isKeyPressed(sf::Keyboard::Right))
      velFinal.x += velocidade;

    if (podePular && isKeyPressed(sf::Keyboard::Up)) {
      pular();
    }
  }
}

void Jogador::executar() { mover(); }

void Jogador::colidir(Entidade *outra, sf::Vector2f intersecao) {
  Personagem::colidir(outra, intersecao);
  InfoColisao info = getInfoColisao(outra, intersecao);

  if (outra->getId() == Ente::ID::INIMIGO) {
    if (info.baixo) {
      Inimigo *inim = static_cast<Inimigo *>(outra);

      pular(static_cast<float>(TAMANHO_TILE) *
            static_cast<float>(std::fmax(
                static_cast<float>(inim->getNivelMaldade()) / 10, 1)) /
            2);

      inim->operator--();

      if (inim->getDeveSerRemovido()) {
        operator*(inim->getNivelMaldade());
      }
    } else {
      neutralizarse();
    }
  }
}

void Jogador::operator*(int fator) {
  pontos += 10 * fator;

  if (pontos % 100)
    num_vidas++;
}

void Jogador::operator++() { operator*(1); }

void Jogador::neutralizarse() {
  num_vidas--;

  // if (num_vidas <= 0)
  //   gameOver();

  setPosicao(posInicial);
}

void Jogador::setNome(const std::string &n) { nome = std::move(n); }
} // namespace Jogo::Entidades::Personagens
