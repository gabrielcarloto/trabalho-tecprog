#pragma once

namespace Jogo {
class Ente {
public:
  Ente();
  ~Ente();

  virtual void executar() = 0;
  void imprimir(){}; // o que eh suposto isso fazer?

protected:
  int id; // pode trocar para um enum?
};
} // namespace Jogo
