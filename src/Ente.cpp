#include "Ente.h"

namespace Jogo {
Ente::Ente() : pFig(nullptr) {}
Ente::~Ente() = default;

void Ente::criaSprite(const char *caminhoTextura, const sf::IntRect *limite) {
  if (pFig != nullptr)
    return;

  carregaTextura(caminhoTextura);

  if (limite)
    pFig = new sf::Sprite(textura, *limite);
  else
    pFig = new sf::Sprite(textura);

  if (!pFig)
    throw std::runtime_error("Nao foi possivel criar sprite");
}

void Ente::inicializaSprite(const char *caminhoTextura,
                            const sf::Vector2f &pos) {
  criaSprite(caminhoTextura);
  pFig->setPosition(pos);
}

void Ente::inicializaSprite(const char *caminhoTextura,
                            const sf::IntRect &limite,
                            const sf::Vector2f &pos) {
  criaSprite(caminhoTextura, &limite);
  pFig->setPosition(pos);
}
} // namespace Jogo
