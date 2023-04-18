#include "game.h"

#include <raylib-cpp.hpp>

game::Game::Game() : title_("Zelda Clone"), window_(raylib::Window(kWidth, kHeight, title_)) {
  SetTargetFPS(60);
  textures_.emplace(Landscape::Earth, new raylib::Texture("res/img/earth.png"));
}

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

