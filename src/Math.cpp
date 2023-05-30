#include "Math.h"
#include <cmath>

namespace Jogo::Math {
float distancia(sf::Vector2f v1, sf::Vector2f v2) {
  sf::Vector2f diff = v1 - v2;
  return std::sqrt(produtoInternoUsual(diff, diff));
}

float produtoInternoUsual(sf::Vector2f v1, sf::Vector2f v2) {
  return v1.x * v2.x + v1.y * v2.y;
}
} // namespace Jogo::Math
