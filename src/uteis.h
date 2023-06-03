#include <functional>
#include <string>

namespace Jogo::Uteis {
void lerArquivo(const char *, const std::function<void(std::string &)> &);
bool chance(unsigned int chance, unsigned int max = 100);
} // namespace Jogo::Uteis
