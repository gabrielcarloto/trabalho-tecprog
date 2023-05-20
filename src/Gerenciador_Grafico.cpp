#include "Gerenciador_Grafico.h"
#include "Ente.h"

namespace Jogo::Gerenciadores {
Gerenciador_Grafico::Gerenciador_Grafico()
    : janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), TITULO_PADRAO) {
  janela.setFramerateLimit(FRAMERATE_PADRAO);
}

void Gerenciador_Grafico::renderizar() { janela.display(); }
void Gerenciador_Grafico::fecharJanela() { janela.close(); }

void Gerenciador_Grafico::desenharEnte(Ente *pE) {
  pE->executar();
  janela.draw(pE->getFigura());
}

bool Gerenciador_Grafico::verificaJanelaAberta() const {
  return janela.isOpen();
}

bool Gerenciador_Grafico::verificarEvento(sf::Event &e) {
  return janela.pollEvent(e);
}

void Gerenciador_Grafico::limparJanela() { janela.clear(); }
float Gerenciador_Grafico::getDeltaTempo() const { return deltaTempo; }

void Gerenciador_Grafico::atualizaDeltaTempo() {
  deltaTempo = relogio.getElapsedTime().asSeconds();
  relogio.restart();
}

Gerenciador_Grafico *Gerenciador_Grafico::instancia(nullptr);

Gerenciador_Grafico *Gerenciador_Grafico::getInstancia() {
  if (instancia == nullptr)
    instancia = new Gerenciador_Grafico();

  // TODO: ajeitar para as threads
  return instancia;
}
} // namespace Jogo::Gerenciadores
