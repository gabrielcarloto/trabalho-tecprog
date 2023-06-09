#pragma once
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
#include <functional>

namespace Jogo {
class Menu : public Ente {
public:
  using CallbackOpcao = std::function<void()>;

  Menu();
  ~Menu() override;

  void limparOpcoes();
  void addOpcao(const char *, const CallbackOpcao &);

  void desenhar() override;
  void executar() override;
  void posicionarBotoes();

private:
  float tempoDesdeUltimaOpcaoSelecionada = 0;
  int opcaoAnteriormenteSelecionada = 0;
  int opcaoSelecionada = 0;
  float larguraBotao = 600;
  float alturaBotao = 50;
  sf::Font fonte;

  std::vector<std::pair<const char *, CallbackOpcao>> opcoes;
  std::vector<sf::RectangleShape *> botoes;
  std::vector<sf::Text *> textos;

  void lidarComInput();
  void pintarBotaoSelecionado();
};
} // namespace Jogo
