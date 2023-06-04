#pragma once
#include "../Ente.h"
#include "../Gerenciador_Colisoes.h"
#include "../entidades/Entidade.h"
#include "../entidades/Projetil.h"
#include "../uteis.h"
#include <functional>
#include <list>
#include <map>
#include <vector>

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
  void adicionarEntidade(Entidades::Projetil *);
  void adicionarJogador(Entidades::Personagens::Jogador *);
  virtual void inicializarMapa() = 0;

protected:
  std::list<Entidades::Entidade *> listaEntidades;
  std::map<const char, std::function<Entidades::Entidade *()>> mapaEntidades;
  std::vector<Entidades::Personagens::Jogador *> listaJogadores;

  void carregarMapa(const char *);
  void adicionarEntidadesDefault();

private:
  void carregarBackground();
  void posicionarJogadores(unsigned int, unsigned int);
  void posicionarEntidade(unsigned int, unsigned int, Entidades::Entidade *);

  Gerenciadores::Gerenciador_Colisoes gerenciadorCol;
};
} // namespace Jogo::Fases
