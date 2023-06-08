#pragma once
#include "entidades/Entidade.h"
#include <list>

namespace Jogo {
// cada evento deve ter o formato CLASSE_EVENTO
enum EVENTOS { JOGADOR_FINALIZAR_FASE, JOGADOR_GAME_OVER };

class Observer {
public:
  virtual ~Observer() = default;
  virtual void tratarEvento(EVENTOS, Entidades::Entidade *) = 0;
};

class Subject {
public:
  Subject() = default;
  virtual ~Subject() = default;

  void adicionarObserver(Observer *po);
  void removerObserver(Observer *po);

protected:
  void notificar(EVENTOS, Entidades::Entidade *);

private:
  std::list<Observer *> observers;
};
} // namespace Jogo
