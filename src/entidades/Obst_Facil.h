#include "Jogador.h"
#include "Obstaculo.h"

constexpr char CHAR_BLOCO = 'B', CHAR_BLOCO_ARRASTAVEL = 'A', CHAR_CHAO = 'C';

namespace Jogo::Entidades::Obstaculos {
class Bloco : public Obstaculo {
public:
  Bloco(const char *, sf::Vector2f = {0, 0}, bool flut = false,
        bool arrastavel = false);
  ~Bloco() override = default;

  void executar() override;
  void colidir(Entidade *, sf::Vector2f) override;

private:
  const bool arrastavel = false;
};
} // namespace Jogo::Entidades::Obstaculos
