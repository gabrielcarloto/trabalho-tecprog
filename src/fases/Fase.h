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

constexpr unsigned int LIMITE_ENTIDADE_ALEATORIA_POR_TIPO = 5;

namespace Jogo::Fases {
class Fase : public Ente, public Observer {
public:
  Fase();
  ~Fase();

  void executar() override;
  bool getExecutando() const;
  void gerenciar_colisoes() { gerenciadorCol.gerenciar(); };

  void removerEntidade(Entidades::Entidade *);
  void adicionarEntidade(Entidades::Projetil *);
  void adicionarJogador(Entidades::Personagens::Jogador *);
  void tratarEvento(EVENTOS, Entidades::Entidade *) override;

  virtual void inicializarMapa() = 0;
  virtual Fase *getProximaFase() const;

protected:
  std::list<Entidades::Entidade *> listaEntidades;
  std::map<const char, std::function<Entidades::Entidade *()>> mapaEntidades;
  std::vector<Entidades::Personagens::Jogador *> listaJogadores;
  Gerenciadores::Gerenciador_Colisoes gerenciadorCol;
  unsigned int contagemPlataformas = 0;
  unsigned int contagemGambas = 0;
  bool jogadorFinalizouFase = false;
  bool executando = true;

  void carregarMapa(const char *);
  void adicionarEntidadesDefault();

  void criarGamba(unsigned int, unsigned int);
  void criarPlataforma(unsigned int, unsigned int);
  Entidades::Entidade *criarInimigo(char, unsigned int, unsigned int);
  Entidades::Entidade *criarObstaculo(char, unsigned int, unsigned int);
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
