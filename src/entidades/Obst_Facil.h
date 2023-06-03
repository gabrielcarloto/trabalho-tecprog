#include "Jogador.h"
#include "Obstaculo.h"

namespace Jogo::Entidades::Obstaculos {
class Obst_Facil : public Obstaculo {
public:
  Obst_Facil(const char *, sf::Vector2f = {0, 0}, bool flut = false,
             bool podeCairQuandoPisa = false);
  ~Obst_Facil() override = default;

  void executar() override;
  void colidirComJogador();

private:
  const bool caiQuandoJogadorPisa = false;
};
} // namespace Jogo::Entidades::Obstaculos
