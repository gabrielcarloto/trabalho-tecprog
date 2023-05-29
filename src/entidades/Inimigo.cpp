#include "Inimigo.h"
#include "Personagem.h"

namespace Jogo::Entidades::Personagens {
Inimigo::Inimigo(const char *path, int maldade, sf::Vector2f pos, float velo)
    : Personagem(Ente::ID::INIMIGO, path, pos, velo), nivelMaldade(maldade) {}

Inimigo::Inimigo(const char *path, sf::IntRect lim, int maldade,
                 sf::Vector2f pos, float velo)
    : Personagem(Ente::ID::INIMIGO, path, lim, pos, velo),
      nivelMaldade(maldade) {}

void Inimigo::morrer() {
  notificar(EVENTOS::INIMIGO_MORTE, this);
  this->~Inimigo();
}
} // namespace Jogo::Entidades::Personagens
