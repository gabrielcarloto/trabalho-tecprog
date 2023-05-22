#include "../Ente.h"
#include "../entidades/Entidade.h"
#include <list>

#define CAMINHO_DATA "./data"
#define CAMINHO_FASES CAMINHO_DATA "/fases"
#define CAMINHO_FASE_PRIMEIRA CAMINHO_FASES "/primeira"
#define CAMINHO_FASE_SEGUNDA CAMINHO_FASES "/segunda"

namespace Jogo::Fases {
class Fase : public Ente {
public:
  Fase();
  ~Fase() = default;
  void executar() override{};
  // void gerenciar_colisoes();
  // void criarInimigosMedios();
  // void criarObstMedios();

protected:
  template <class E, typename... Args> void carregarMapa(const char *, Args...);

  std::list<Entidades::Entidade *> listaEntidades;

private:
  void carregarBackground();
};
} // namespace Jogo::Fases
