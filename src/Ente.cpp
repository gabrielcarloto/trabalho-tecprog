#include "Ente.h"

namespace Jogo {
Ente::Ente() : pFig(nullptr) {}
Ente::~Ente() = default;

void Ente::inicializaSprite(const char *caminhoTextura) {
  if (pFig != nullptr)
    return;

  carregaTextura(caminhoTextura);
  pFig = new sf::Sprite(textura);

  if (!pFig)
    throw std::runtime_error("Nao foi possivel criar sprite");
}

void Ente::inicializaSprite(const char *caminhoTextura, sf::IntRect limite) {
  if (pFig != nullptr)
    return;

  carregaTextura(caminhoTextura);
  pFig = new sf::Sprite(textura, limite);

  if (!pFig)
    throw std::runtime_error("Nao foi possivel criar sprite");
}
} // namespace Jogo
