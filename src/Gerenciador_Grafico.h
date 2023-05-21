#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"

constexpr const char *TITULO_PADRAO = "Jogo++";
constexpr const unsigned int LARGURA_JANELA = 1280, ALTURA_JANELA = 720,
                             FRAMERATE_PADRAO = 60;

namespace Jogo {
class Ente;

namespace Gerenciadores {
class Gerenciador_Grafico {
public:
  ~Gerenciador_Grafico() = default;

  void renderizar();
  void limparJanela();
  void fecharJanela();
  void atualizaDeltaTempo();
  void desenharEnte(Ente *);
  bool verificaJanelaAberta() const;
  bool verificarEvento(sf::Event &);
  float getDeltaTempo() const;

  static Gerenciador_Grafico *getInstancia();

private:
  Gerenciador_Grafico();
  sf::RenderWindow janela;
  sf::Clock relogio;
  float deltaTempo = 0;

  static Gerenciador_Grafico *instancia;
};
} // namespace Gerenciadores
} // namespace Jogo
