#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <stdexcept>

namespace Jogo {
class Ente {
public:
  Ente();
  ~Ente();

  virtual void executar() = 0;
  void desenhar(){};

protected:
  int id; // pode trocar para um enum?
  sf::Sprite *pFig;
  sf::Texture textura;

  void inicializaSprite(const char *caminhoTextura);
  void inicializaSprite(const char *caminhoTextura, sf::IntRect limite);

private:
  void carregaTextura(const char *caminho) { textura.loadFromFile(caminho); }
};
} // namespace Jogo
