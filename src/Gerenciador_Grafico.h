#pragma once
#include "SFML/Graphics/Shape.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <map>

constexpr unsigned int TAMANHO_TILE = 64, MAX_JOGADORES = 2;
constexpr unsigned int NUM_TILES_Y = 12, LARGURA_JANELA = 1178,
                       ALTURA_JANELA = TAMANHO_TILE * (NUM_TILES_Y - 1),
                       FRAMERATE_PADRAO = 60;

constexpr const char *TITULO_PADRAO = "SunnyLand++";

#define CAMINHO_ASSETS "./assets"
#define CAMINHO_FONTES CAMINHO_ASSETS "/fonts"
#define CAMINHO_IMAGENS CAMINHO_ASSETS "/images"

namespace Jogo {
class Ente;

namespace Gerenciadores {
class Gerenciador_Grafico {
public:
  ~Gerenciador_Grafico();

  void renderizar();
  void limparJanela();
  void fecharJanela();
  void atualizaDeltaTempo();
  void desenharEnte(Ente *);
  void atualizarView();
  void atualizarView(sf::Vector2f);
  void setLimitesMapa(float, float);
  void desenharFigura(const sf::Shape &);
  void desenharTexto(const sf::Text &);

  bool verificaJanelaAberta() const;
  bool verificarEvento(sf::Event &);
  float getDeltaTempo() const;

  sf::Texture *carregarTextura(const char *);

  static Gerenciador_Grafico *getInstancia();
  static void deletarInstancia();

private:
  Gerenciador_Grafico();

  sf::RenderWindow janela;
  sf::Clock relogio;
  sf::View view;

  float deltaTempo = 0;
  static Gerenciador_Grafico *instancia;
  float limiteMapaX = 0, limiteMapaY = 0;
  std::map<const char *, sf::Texture *> mapaTexturas;
};
} // namespace Gerenciadores
} // namespace Jogo
