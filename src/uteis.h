#pragma once
#include <functional>
#include <string>

namespace Jogo::Uteis {
void lerArquivo(const char *, const std::function<void(std::string &)> &);
bool chance(unsigned int chance, unsigned int max = 100);

// https://en.cppreference.com/w/cpp/iterator/next cópia do std::next caso seja
// obrigatório utilizar o C++03
template <class IT>
IT next(IT it, typename std::iterator_traits<IT>::difference_type n = 1) {
  std::advance(it, n);
  return it;
}

// https://en.cppreference.com/w/cpp/iterator/next cópia do std::prev caso seja
// obrigatório utilizar o C++03
template <class IT>
IT prev(IT it, typename std::iterator_traits<IT>::difference_type n = 1) {
  std::advance(it, -n);
  return it;
}
} // namespace Jogo::Uteis
//
