#include "Observer.h"

namespace Jogo {
void Subject::adicionarObserver(Observer *po) { observers.push_back(po); }
void Subject::removerObserver(Observer *po) { observers.remove(po); }

void Subject::notificar(int idEvento, Entidades::Entidade *pEnt) {
  for (auto observer : observers) {
    observer->atualizar(idEvento, pEnt);
  }
}
} // namespace Jogo
