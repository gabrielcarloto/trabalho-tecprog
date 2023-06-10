#include "ListaEntidades.h"
#include <iostream>

namespace Jogo::Listas {
void ListaEntidades::incluir(Entidades::Entidade *p) { LEs.incluir(p); }
void ListaEntidades::remover(Entidades::Entidade *p) { LEs.remover(p); }
std::size_t ListaEntidades::getTamanho() const { return LEs.getTamanho(); }
ListaEntidades::IteratorEntidades ListaEntidades::end() { return LEs.end(); }

ListaEntidades::IteratorEntidades ListaEntidades::begin() {
  return LEs.begin();
}

void ListaEntidades::percorrer() const {
  ElementoEntidade *aux = LEs.getPrimeiro();

  while (aux != nullptr) {
    std::cout << aux << '\n';
    aux = aux->getProximo();
  }
}
} // namespace Jogo::Listas
