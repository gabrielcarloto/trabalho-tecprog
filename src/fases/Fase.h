#include "../Ente.h"
#include "../entidades/Entidade.h"
#include "../uteis.h"
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
  void executar() override;
  // void gerenciar_colisoes();
  // void criarInimigosMedios();
  // void criarObstMedios();

  template <class E, typename... Args>
  void carregarMapa(const char *path, Args... args) {
    static_assert(std::is_base_of_v<Entidades::Entidade, E>);

    unsigned int indiceLinha = 0;
    Uteis::lerArquivo(path, [&args..., this, &indiceLinha](auto &linha) {
      unsigned int indiceEntidade = 0;

      for (auto caractere : linha) {
        if (caractere != '1') {
          indiceEntidade++;
          continue;
        }

        E *entidade = new E(std::forward<Args>(args)...);

        // TODO: adicionar no gerenciador de obstaculos com switch/case usando
        // os IDs

        listaEntidades.push_back(entidade);
        entidade->setEscalaFigura(2, 2);
        entidade->setPosicao(
            {indiceEntidade * TAMANHO_TILE, indiceLinha * TAMANHO_TILE});

        indiceEntidade++;
      }

      indiceLinha++;
    });
  }

protected:
  std::list<Entidades::Entidade *> listaEntidades;

private:
  void carregarBackground();
};
} // namespace Jogo::Fases
