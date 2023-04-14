#include "game.h"

#include <raylib-cpp.hpp>

#define MAX_FRAME_SPEED 15
#define MIN_FRAME_SPEED 1

game::Game::Game() : title_("Zelda Clone") { SetTargetFPS(60); }

bool game::Game::IsRunning() { return !window_.ShouldClose(); }

void game::Game::Draw() {
  raylib::Color textColor = raylib::Color::LightGray();
  BeginDrawing();
  {
    window_.ClearBackground(RAYWHITE);
    textColor.DrawText("Congrats! You created your first window!", 190, 200,
                       50);
  }
  EndDrawing();
}

game::Game& game::Game::Next() { return *this; }

game::Game& game::Game::Poll() {
  if (IsKeyPressed(KEY_ESCAPE)) {
    window_.Close();
  }
  return *this;
}

game::World::World() { cells_.reserve(kWidth * kHeight); }