#include "Entidade.h"
namespace Jogo::Entidades::Obstaculos {
class Obstaculo : public Entidade {
public:
  Obstaculo(bool dano) : danoso(dano) { id = Ente::OBSTACULO; }
  virtual ~Obstaculo() = default;

protected:
  const bool danoso;
};
} // namespace Jogo::Entidades::Obstaculos
