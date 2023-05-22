#include "../Ente.h"

namespace Jogo::Fases {
class Fase : public Ente {
public:
  Fase();
  ~Fase() = default;
  void executar() override{};
  // void gerenciar_colisoes();
  // void criarInimigosMedios();
  // void criarObstMedios();

private:
  void carregarBackground();
};
} // namespace Jogo::Fases
