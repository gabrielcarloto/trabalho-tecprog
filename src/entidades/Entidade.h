#include "../Ente.h"
#include "SFML/Graphics/CircleShape.hpp"

namespace Jogo::Entidades {
class Entidade : public Ente {
public:
  Entidade();
  ~Entidade();

protected:
  int x, y;
};
} // namespace Jogo::Entidades
