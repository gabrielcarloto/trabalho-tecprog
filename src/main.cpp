#include "Jogo.h"
#include <cstdlib>
#include <ctime>

int main() {
  std::srand(std::time(nullptr));
  Jogo::Jogo principal;

  principal.executar();

  return 0;
}
