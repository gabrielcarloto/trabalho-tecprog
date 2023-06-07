#pragma once
#include "Jogador.h"
#include "Obstaculo.h"
#include <array>

constexpr float RAIO_PADRAO_CAIXA_VENENOSA = 150.f;
constexpr char CHAR_CAIXA_VENENOSA = 'V';

namespace Jogo::Entidades::Obstaculos {
// Obstáculo difícil
class CaixaVenenosa : public Obstaculo {
public:
  CaixaVenenosa(const char *, sf::Vector2f = {0, 0}, bool = false,
                float = RAIO_PADRAO_CAIXA_VENENOSA);

  ~CaixaVenenosa() override = default;

  void executar() override;
  void colidir(Entidade *, sf::Vector2f) override;
  void setPosicao(const sf::Vector2f &) override;
  void incluirJogador(Personagens::Jogador *);
  void desenhar() override;
  void mover() override;

private:
  float raioVeneno;
  sf::CircleShape veneno;

  unsigned int numJogadores = 0;
  std::array<Personagens::Jogador *, MAX_JOGADORES> jogadores;
  std::array<float, MAX_JOGADORES> tempoJogadoresEnvenenados;

  void danificarJogadores();
  std::array<float, MAX_JOGADORES> distanciaJogadores();
};
} // namespace Jogo::Entidades::Obstaculos
