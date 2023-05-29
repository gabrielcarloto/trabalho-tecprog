#include "Obstaculo.h"

namespace Jogo::Entidades::Obstaculos {
class Obst_Facil : public Obstaculo {
public:
  Obst_Facil(const char *, sf::Vector2f = {0, 0});
  ~Obst_Facil() override = default;

  void executar() override; // TODO: implementar
  void mover() override{};
};
} // namespace Jogo::Entidades::Obstaculos
