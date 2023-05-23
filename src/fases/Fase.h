#include "../Ente.h"
#include "../entidades/Entidade.h"
#include "../uteis.h"
#include <functional>
#include <list>
#include <map>

#define CAMINHO_DATA "./data"
#define CAMINHO_FASES CAMINHO_DATA "/fases"
#define CAMINHO_FASE_PRIMEIRA CAMINHO_FASES "/primeira"
#define CAMINHO_FASE_SEGUNDA CAMINHO_FASES "/segunda"

namespace Jogo::Fases {
class Fase : public Ente {
public:
  Fase();
  ~Fase() = default; // TODO: liberar memória no listaEntidades
  void executar() override;
  // void gerenciar_colisoes();
  // void criarInimigosMedios();
  // void criarObstMedios();

  void carregarMapa(const char *);
  std::map<const char, std::function<Entidades::Entidade *()>> mapaEntidades;

protected:
  std::list<Entidades::Entidade *> listaEntidades;

private:
  void carregarBackground();
};
} // namespace Jogo::Fases
