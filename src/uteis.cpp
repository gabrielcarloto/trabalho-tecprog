#include "uteis.h"
#include <fstream>
#include <stdexcept>

namespace Jogo::Uteis {
void lerArquivo(const char *path,
                const std::function<void(std::string &)> &forEachLineCallback) {
  std::string line;
  std::ifstream file(path);

  if (!file.is_open()) {
    throw std::runtime_error(std::string("Unable to open file: ") + path);
  }

  while (getline(file, line))
    forEachLineCallback(line);

  file.close();
}

bool chance(unsigned int chance, unsigned int max) {
  return std::rand() % max < chance;
}
} // namespace Jogo::Uteis
