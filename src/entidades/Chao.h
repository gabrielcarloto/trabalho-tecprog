#include "Obstaculo.h"

namespace Jogo::Entidades::Obstaculos {
class Chao : public Obstaculo {
public:
  Chao(const char *, sf::Vector2f = {0, 0});
  ~Chao() override = default;

  void executar() override;
  void mover() override{};
};
} // namespace Jogo::Entidades::Obstaculos
