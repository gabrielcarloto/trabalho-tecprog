#include "Ente.h"

namespace Jogo {
Ente::Ente(ID idEnte) : id(idEnte), pFig(nullptr) {
  if (!pGG)
    pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
}

Ente::~Ente() {
  delete pFig;
  pFig = nullptr;
};

Gerenciadores::Gerenciador_Grafico *Ente::pGG = nullptr;

void Ente::desenhar() { pGG->desenharEnte(this); }
const sf::Sprite &Ente::getFigura() const { return *pFig; };

void Ente::criaSprite(const char *caminhoTextura, const sf::IntRect *limite) {
  if (pFig != nullptr)
    return;

  auto textura = pGG->carregarTextura(caminhoTextura);

  if (limite)
    pFig = new sf::Sprite(*textura, *limite);
  else
    pFig = new sf::Sprite(*textura);

  if (!pFig)
    throw std::runtime_error("Nao foi possivel criar sprite");
}

void Ente::inicializaSprite(const char *caminhoTextura,
                            const sf::Vector2f &pos) {
  criaSprite(caminhoTextura);
  pFig->setPosition(pos);
}

void Ente::setEscalaFigura(float fatorX, float fatorY) {
  pFig->setScale(fatorX, fatorY);
}

void Ente::inicializaSprite(const char *caminhoTextura,
                            const sf::IntRect &limite,
                            const sf::Vector2f &pos) {
  criaSprite(caminhoTextura, &limite);
  pFig->setPosition(pos);
}
} // namespace Jogo
