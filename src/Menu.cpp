#include "Menu.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#include <iostream>
#include <utility>

constexpr sf::Uint8 COR_PADRAO_MENU_R = 89, COR_PADRAO_MENU_G = 23,
                    COR_PADRAO_MENU_B = 61, COR_PADRAO_TEXTO_R = 240,
                    COR_PADRAO_TEXTO_G = 201, COR_PADRAO_TEXTO_B = 103,
                    DIFERENCA_BRILHO_SELECIONADO = 30;

namespace Jogo {
Menu::Menu() : Ente(Ente::ID::MENU) {
  inicializaSprite(CAMINHO_IMAGENS "/back.png", {0, 0});
  fonte.loadFromFile(CAMINHO_FONTES "/8-BIT WONDER.TTF");
}

Menu::~Menu() {
  for (auto botao : botoes) {
    delete botao;
  }

  for (auto texto : textos) {
    delete texto;
  }
}

void Menu::desenhar() {
  Ente::desenhar();

  for (auto botao : botoes) {
    pGG->desenharFigura(*botao);
  }

  for (auto texto : textos) {
    pGG->desenharTexto(*texto);
  }
}

void Menu::executar() {
  tempoDesdeUltimaOpcaoSelecionada += pGG->getDeltaTempo();

  lidarComInput();
  pintarBotaoSelecionado();
}

void Menu::addOpcao(const char *op, const CallbackOpcao &cb) {
  if (op == nullptr)
    throw std::runtime_error(
        "Menu::addOpcao -> Tentativa de adicionar opcao nula");

  opcoes.emplace_back(op, std::move(cb));

  sf::Text *texto = new sf::Text(op, fonte);
  texto->setFillColor(
      sf::Color(COR_PADRAO_TEXTO_R, COR_PADRAO_TEXTO_G, COR_PADRAO_TEXTO_B));

  textos.push_back(texto);

  sf::RectangleShape *retangulo =
      new sf::RectangleShape({larguraBotao, alturaBotao});

  retangulo->setFillColor(
      sf::Color(COR_PADRAO_MENU_R, COR_PADRAO_MENU_G, COR_PADRAO_MENU_B));
  botoes.push_back(retangulo);
}

void Menu::limparOpcoes() {
  opcoes.clear();
  textos.clear();
  botoes.clear();
}

void Menu::posicionarBotoes() {
  const float INICIO_COORDS_Y = static_cast<float>(ALTURA_JANELA) /
                                static_cast<float>(opcoes.size() + 1),
              COORD_X = (LARGURA_JANELA - larguraBotao) / 2;

  for (size_t i = 0; i < botoes.size(); i++) {
    const float posY = INICIO_COORDS_Y * static_cast<float>(i + 1);

    botoes[i]->setPosition(COORD_X, posY);

    sf::FloatRect globalBoundsTexto = textos[i]->getGlobalBounds();
    textos[i]->setPosition(
        COORD_X + (larguraBotao - globalBoundsTexto.width) / 2,
        posY + (alturaBotao - (globalBoundsTexto.height + 10)) / 2);
  }
}

void Menu::lidarComInput() {
  if (tempoDesdeUltimaOpcaoSelecionada <= 0.1f)
    return;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    tempoDesdeUltimaOpcaoSelecionada = 0;
    opcaoAnteriormenteSelecionada = opcaoSelecionada;
    opcaoSelecionada = (opcaoSelecionada + 1) % (int)opcoes.size();
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    opcaoAnteriormenteSelecionada = opcaoSelecionada;
    tempoDesdeUltimaOpcaoSelecionada = 0;
    opcaoSelecionada--;
    if (opcaoSelecionada < 0)
      opcaoSelecionada = static_cast<int>(opcoes.size()) - 1;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    tempoDesdeUltimaOpcaoSelecionada = 0;
    opcoes[opcaoSelecionada].second();
  }
}

void Menu::pintarBotaoSelecionado() {
  sf::RectangleShape *botaoAnterior = botoes[opcaoAnteriormenteSelecionada],
                     *botaoAtual = botoes[opcaoSelecionada];
  sf::Text *textoAnterior = textos[opcaoAnteriormenteSelecionada],
           *textoAtual = textos[opcaoSelecionada];

  botaoAnterior->setFillColor(
      sf::Color(COR_PADRAO_MENU_R, COR_PADRAO_MENU_G, COR_PADRAO_MENU_B));
  textoAnterior->setFillColor(
      sf::Color(COR_PADRAO_TEXTO_R, COR_PADRAO_TEXTO_G, COR_PADRAO_TEXTO_B));

  botaoAtual->setFillColor(
      sf::Color(COR_PADRAO_MENU_R + DIFERENCA_BRILHO_SELECIONADO,
                COR_PADRAO_MENU_G + DIFERENCA_BRILHO_SELECIONADO,
                COR_PADRAO_MENU_B + DIFERENCA_BRILHO_SELECIONADO));

  textoAtual->setFillColor(
      sf::Color(255, COR_PADRAO_TEXTO_G + DIFERENCA_BRILHO_SELECIONADO,
                COR_PADRAO_TEXTO_B + DIFERENCA_BRILHO_SELECIONADO));
}
} // namespace Jogo
