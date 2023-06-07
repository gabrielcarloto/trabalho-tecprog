#pragma once
#include "SFML/Graphics/Shape.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
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
  void desenharFigura(const sf::Shape &);

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
  float deltaTempo = 0;

  std::map<const char *, sf::Texture *> mapaTexturas;

  static Gerenciador_Grafico *instancia;
};
} // namespace Gerenciadores
} // namespace Jogo
