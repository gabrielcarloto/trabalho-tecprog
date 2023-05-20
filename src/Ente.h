#pragma once
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>

namespace Jogo {
class Ente {
public:
  Ente();
  ~Ente();

  virtual void executar() = 0;
  void desenhar();
  const sf::Sprite &getFigura() const;

protected:
  int id; // pode trocar para um enum?
  sf::Sprite *pFig;
  sf::Texture textura;
  static Gerenciadores::Gerenciador_Grafico *pGG;

  void inicializaSprite(const char *, const sf::Vector2f &);
  void inicializaSprite(const char *, const sf::IntRect &,
                        const sf::Vector2f &);

private:
  void carregaTextura(const char *caminho) { textura.loadFromFile(caminho); }
  void criaSprite(const char *, const sf::IntRect * = nullptr);
};
} // namespace Jogo
