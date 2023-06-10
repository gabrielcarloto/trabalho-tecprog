#include "Lista.h"
#include "entidades/Entidade.h"

namespace Jogo::Listas {
class ListaEntidades {
  using LEntidades = Lista<Entidades::Entidade>;
  using ElementoEntidade = LEntidades::Elemento<Entidades::Entidade>;
  using IteratorEntidades = LEntidades::ListIterator<Entidades::Entidade>;

public:
  ListaEntidades() = default;
  ~ListaEntidades() = default;

  void incluir(Entidades::Entidade *);
  void remover(Entidades::Entidade *);
  void percorrer() const;

  std::size_t getTamanho() const;

  IteratorEntidades begin();
  IteratorEntidades end();

private:
  LEntidades LEs;
};
} // namespace Jogo::Listas
