#include "Jogador.h"
#include <SFML/Graphics.hpp>

namespace Jogo::Entidades::Personagens {
void Jogador::mover() {
  auto isKeyPressed = sf::Keyboard::isKeyPressed;

  if (isKeyPressed(sf::Keyboard::W))
    y -= static_cast<int>(vel.y);
  if (isKeyPressed(sf::Keyboard::A))
    x -= static_cast<int>(vel.x);
  if (isKeyPressed(sf::Keyboard::S))
    y += static_cast<int>(vel.y);
  if (isKeyPressed(sf::Keyboard::D))
    x += static_cast<int>(vel.x);

  pFig->setPosition(static_cast<float>(x), static_cast<float>(y));

  if(x < 0 ){
    pFig->setPosition(0,y);
  }
  if(x > (int)LARGURA_JANELA){
    pFig->setPosition(x-64,y);
  }
  if(y < 0 ){
    pFig->setPosition(x,0);
  }
  if(y > (int)ALTURA_JANELA){
    pFig->setPosition(y,y-64);
  }
}

void Jogador::setEscalaFigura(float fatorX, float fatorY) {
  pFig->setScale(fatorX, fatorY);
}

void Jogador::executar() { mover(); }
} // namespace Jogo::Entidades::Personagens
