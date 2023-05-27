#pragma once
#include "entidades/Obstaculo.h"
#include <list>

namespace Jogo::Gerenciadores {
class Gerenciador_Colisoes {
public:
  Gerenciador_Colisoes() = default;
  ~Gerenciador_Colisoes() = default;

  void incluirObstaculo(Entidades::Obstaculos::Obstaculo *);
  // void incluirInimigo(Inimigo *);
private:
  // std::vector<Inimigo *> LIs;
  std::list<Entidades::Obstaculos::Obstaculo *> LOs;
};
} // namespace Jogo::Gerenciadores
