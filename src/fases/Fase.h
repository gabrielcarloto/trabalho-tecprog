#pragma once
#include "../Ente.h"
#include "../Gerenciador_Colisoes.h"
#include "../entidades/Entidade.h"
#include "../entidades/Gamba.h"
#include "../entidades/Plataforma.h"
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

  void removerEntidade(Entidades::Entidade *);
  void adicionarEntidade(Entidades::Projetil *);
  void adicionarJogador(Entidades::Personagens::Jogador *);
  virtual void inicializarMapa() = 0;

protected:
  std::list<Entidades::Entidade *> listaEntidades;
  std::map<const char, std::function<Entidades::Entidade *()>> mapaEntidades;
  std::vector<Entidades::Personagens::Jogador *> listaJogadores;
  Gerenciadores::Gerenciador_Colisoes gerenciadorCol;

  void carregarMapa(const char *);
  void adicionarEntidadesDefault();

  void criarGamba(unsigned int, unsigned int);
  void criarPlataforma(unsigned int, unsigned int);
  Entidades::Entidade *criarEntidadeComChance(char, unsigned int = 1);
  virtual void criarEntidadeAleatoriamente(unsigned int, unsigned int) = 0;

  sf::Vector2f indiceParaPosicao(sf::FloatRect, unsigned int, unsigned int);

private:
  void carregarBackground();
  void posicionarJogadores(unsigned int, unsigned int);
  void posicionarEntidade(unsigned int, unsigned int, Entidades::Entidade *);
  void adicionarJogadoresNasEntidades();
};
} // namespace Jogo::Fases
