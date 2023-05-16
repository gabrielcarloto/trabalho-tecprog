#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <stdexcept>

namespace Jogo {
class Ente {
public:
  Ente() : pFig(nullptr) {}
  ~Ente();

  virtual void executar() = 0;
  void desenhar(){};

protected:
  int id; // pode trocar para um enum?
  sf::Sprite *pFig;
  sf::Texture textura;

  void inicializaSprite(const char *caminhoTextura) {
    if (pFig != nullptr)
      return;

    carregaTextura(caminhoTextura);
    pFig = new sf::Sprite(textura);

    if (!pFig)
      throw std::runtime_error("Nao foi possivel criar sprite");
  }

  void inicializaSprite(const char *caminhoTextura, sf::IntRect limite) {
    if (pFig != nullptr)
      return;

    carregaTextura(caminhoTextura);
    pFig = new sf::Sprite(textura, limite);

    if (!pFig)
      throw std::runtime_error("Nao foi possivel criar sprite");
  }

private:
  void carregaTextura(const char *caminho) { textura.loadFromFile(caminho); }
};
} // namespace Jogo
