#include "Jogador.h"
#include "Obstaculo.h"

constexpr char CHAR_PLATAFORMA = 'P';

namespace Jogo::Entidades::Obstaculos {
// obstáculo médio
class Plataforma : public Obstaculo {
public:
  Plataforma(const char *, sf::Vector2f = {0, 0},
             bool podeCairQuandoPisa = false);
  ~Plataforma() override = default;

  void executar() override;
  void colidir(Entidade *, sf::Vector2f) override;

private:
  const bool caiQuandoJogadorPisa = false;
};
} // namespace Jogo::Entidades::Obstaculos
