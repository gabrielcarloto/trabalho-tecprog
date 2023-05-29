#include "Inim_Facil.h"

constexpr int MALDADE_PADRAO_FACIL = 3;

namespace Jogo::Entidades::Personagens {
Inim_Facil::Inim_Facil(const char *path, sf::Vector2f pos, float velo)
    : Inimigo(path, MALDADE_PADRAO_FACIL, pos, velo) {}

Inim_Facil::Inim_Facil(const char *path, sf::IntRect lim, sf::Vector2f pos,
                       float velo)
    : Inimigo(path, lim, MALDADE_PADRAO_FACIL, pos, velo) {}

void Inim_Facil::executar() { mover(); }
void Inim_Facil::mover() {} // TODO: implementar

void Inim_Facil::tomarDano() {
  num_vidas--;

  if (num_vidas <= 0)
    morrer();
}
} // namespace Jogo::Entidades::Personagens
