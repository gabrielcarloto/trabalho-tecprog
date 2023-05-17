#include "Gerenciador_Grafico.h"

namespace Jogo::Gerenciadores {
Gerenciador_Grafico::Gerenciador_Grafico()
    : janela(sf::VideoMode(384, 240), "Jogo") {
  janela.setFramerateLimit(60);
}
} // namespace Jogo::Gerenciadores
