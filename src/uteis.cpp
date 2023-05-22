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

} // namespace Jogo::Uteis
