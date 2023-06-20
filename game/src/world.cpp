#include <cstddef>

#include "Vector2.hpp"
#include "game.h"

void game::World::FillWithEarth() {
  for (size_t i = 0; i < kWidth; i += 1) {
    for (size_t j = 0; j < kHeight; j += 1) {
      cells_[i][j] = Cell(Landscape::kEarth);
    }
  }
}

template <size_t Width, size_t Height>
game::Matrix2D<game::Cell, Width, Height> game::World::Project(
    raylib::Camera2D cam) {}
