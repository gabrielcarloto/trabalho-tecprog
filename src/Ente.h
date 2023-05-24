#pragma once
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>

namespace Jogo {
class Ente {
public:
  Ente();
  ~Ente();

  virtual void executar() = 0;

  void desenhar();
  void setEscalaFigura(float, float);
  const sf::Sprite &getFigura() const;
  int getId() const { return id; }

  enum ID { JOGADOR, INIMIGO, OBSTACULO, PROJETIL, FASE, CHAO };

protected:
  ID id; // TODO: trocar para const
  sf::Sprite *pFig;
  static Gerenciadores::Gerenciador_Grafico *pGG;

  void inicializaSprite(const char *, const sf::Vector2f &);
  void inicializaSprite(const char *, const sf::IntRect &,
                        const sf::Vector2f &);

private:
  void criaSprite(const char *, const sf::IntRect * = nullptr);
};
} // namespace Jogo
