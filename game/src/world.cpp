#include <cstddef>

#include "Vector2.hpp"
#include "game.h"

void game::World::FillWithEarth() {
  for (size_t i = 0; i < kWidth; i += 1) {
    for (size_t j = 0; j < kHeight; j += 1) {
      cells_[i][j] = Cell(Landscape::Earth);
    }
  }
}

template <size_t width, size_t height>
game::Matrix2D<game::Cell, width, height> game::World::Project(
    raylib::Camera2D cam) {}
