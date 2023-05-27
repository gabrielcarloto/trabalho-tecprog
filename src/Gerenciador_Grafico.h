#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <map>

constexpr const char *TITULO_PADRAO = "Jogo++";
constexpr const unsigned int LARGURA_JANELA = 1178, ALTURA_JANELA = 736,
                             FRAMERATE_PADRAO = 60;

constexpr const unsigned int TAMANHO_TILE = 64;

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

  bool verificaJanelaAberta() const;
  bool verificarEvento(sf::Event &);
  float getDeltaTempo() const;

  sf::Texture *carregarTextura(const char *);

  static Gerenciador_Grafico *getInstancia();

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
