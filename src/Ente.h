#pragma once
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>

namespace Jogo {
class Ente {
public:
  enum ID { JOGADOR, INIMIGO, OBSTACULO, PROJETIL, FASE, MENU };

  Ente(ID);
  virtual ~Ente();

  virtual void executar() = 0;

  virtual void desenhar();
  void setEscalaFigura(float, float);
  const sf::Sprite &getFigura() const;

  ID getId() const { return id; }

protected:
  const ID id;
  sf::Sprite *pFig = nullptr;
  static Gerenciadores::Gerenciador_Grafico *pGG;

  void inicializaSprite(const char *, const sf::Vector2f &);
  void inicializaSprite(const char *, const sf::IntRect &,
                        const sf::Vector2f &);

private:
  void criaSprite(const char *, const sf::IntRect * = nullptr);
};
} // namespace Jogo
