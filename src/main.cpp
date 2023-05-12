#include "entidades/Jogador.h"
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  window.setFramerateLimit(60);

  Jogo::Entidades::Personagens::Jogador teste;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape)
          window.close();
    }

    window.clear();
    window.draw(teste.getShape());
    window.display();
  }

  return 0;
}
