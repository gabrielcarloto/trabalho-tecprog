#pragma once
#include "entidades/Entidade.h"
#include <list>

namespace Jogo {
// cada evento deve ter o formato CLASSE_EVENTO
enum EVENTOS {
  INIMIGO_MORTE,
};

class Observer {
public:
  virtual ~Observer() = default;

  virtual void atualizar(int, Entidades::Entidade *) = 0;
};

class Subject {
public:
  Subject() = default;
  virtual ~Subject() = default;

  void adicionarObserver(Observer *po);
  void removerObserver(Observer *po);

protected:
  void notificar(int, Entidades::Entidade *);

private:
  std::list<Observer *> observers;
};
} // namespace Jogo
