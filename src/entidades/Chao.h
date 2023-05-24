#include "Entidade.h"

namespace Jogo::Entidades {
class Chao : public Entidade {
public:
  Chao(const char *, sf::Vector2f = {0, 0});
  ~Chao() = default;

  void executar() override;
};
} // namespace Jogo::Entidades
