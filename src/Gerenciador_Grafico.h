#pragma once
#include "SFML/Graphics/RenderWindow.hpp"

constexpr const char *TITULO_PADRAO = "Jogo++";
constexpr const unsigned int LARGURA_JANELA = 384, ALTURA_JANELA = 240,
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
  void desenharEnte(Ente *);
  bool verificaJanelaAberta() const;
  bool verificarEvento(sf::Event &);

  static Gerenciador_Grafico *getInstancia();

private:
  Gerenciador_Grafico();
  sf::RenderWindow janela;

  static Gerenciador_Grafico *instancia;
};
} // namespace Gerenciadores
} // namespace Jogo
