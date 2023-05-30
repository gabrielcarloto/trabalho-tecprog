#pragma once
#include "../Ente.h"
#include "../Gerenciador_Colisoes.h"
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
  ~Fase();

  void executar() override;
  void gerenciar_colisoes() { gerenciadorCol.gerenciar(); };
  // void criarInimigosMedios();
  // void criarObstMedios();

  void removerEntidade(Entidades::Entidade *);

protected:
  std::list<Entidades::Entidade *> listaEntidades;
  std::map<const char, std::function<Entidades::Entidade *()>> mapaEntidades;

  void carregarMapa(const char *);
  void adicionarEntidadesDefault();

private:
  void carregarBackground();

  Gerenciadores::Gerenciador_Colisoes gerenciadorCol;
};
} // namespace Jogo::Fases
