#include "Gerenciador_Grafico.h"
#include "Ente.h"
#include "SFML/Graphics/Texture.hpp"
#include <algorithm>
#include <cstring>

namespace Jogo::Gerenciadores {
Gerenciador_Grafico::Gerenciador_Grafico()
    : janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), TITULO_PADRAO) {
  janela.setFramerateLimit(FRAMERATE_PADRAO);
}

Gerenciador_Grafico::~Gerenciador_Grafico() {
  for (auto textura : mapaTexturas) {
    delete textura.second;
    textura.second = nullptr;
  }
}

void Gerenciador_Grafico::renderizar() { janela.display(); }
void Gerenciador_Grafico::fecharJanela() { janela.close(); }

void Gerenciador_Grafico::desenharEnte(Ente *pE) {
  janela.draw(pE->getFigura());
}

bool Gerenciador_Grafico::verificaJanelaAberta() const {
  return janela.isOpen();
}

bool Gerenciador_Grafico::verificarEvento(sf::Event &e) {
  return janela.pollEvent(e);
}

void Gerenciador_Grafico::limparJanela() { janela.clear(); }
float Gerenciador_Grafico::getDeltaTempo() const {
#ifdef DEBUG
  // dependendo da forma que o jogo está sendo debugado, pode levar muito tempo
  // entre um frame e outro, fazendo com que a velocidade seja multiplicada por
  // um valor grande, levando as entidades para fora da tela; isso mantém o
  // cálculo da velocidade de forma que isso não aconteça
  return 1 / static_cast<float>(FRAMERATE_PADRAO);
#else
  return deltaTempo;
#endif // DEBUG
}

void Gerenciador_Grafico::atualizaDeltaTempo() {
  deltaTempo = relogio.getElapsedTime().asSeconds();
  relogio.restart();
}

sf::Texture *Gerenciador_Grafico::carregarTextura(const char *path) {
  auto it =
      std::find_if(mapaTexturas.begin(), mapaTexturas.end(),
                   [path](auto item) { return !strcmp(path, item.first); });

  if (it != mapaTexturas.end())
    return it->second;

  auto *textura = new sf::Texture;
  textura->loadFromFile(path);

  mapaTexturas[path] = textura;

  return textura;
}

Gerenciador_Grafico *Gerenciador_Grafico::instancia(nullptr);

Gerenciador_Grafico *Gerenciador_Grafico::getInstancia() {
  if (instancia == nullptr)
    instancia = new Gerenciador_Grafico();

  // TODO: ajeitar para as threads
  return instancia;
}

void Gerenciador_Grafico::deletarInstancia() { delete instancia; }
} // namespace Jogo::Gerenciadores
