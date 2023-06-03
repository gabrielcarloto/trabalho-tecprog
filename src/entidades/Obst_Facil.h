#include "Obstaculo.h"

namespace Jogo::Entidades::Obstaculos {
class Obst_Facil : public Obstaculo {
public:
  Obst_Facil(const char *, sf::Vector2f = {0, 0}, bool flut = true);
  ~Obst_Facil() override = default;

  void executar() override;
};
} // namespace Jogo::Entidades::Obstaculos
