#include "game.h"

#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>

#include <raylib-cpp.hpp>

#include "Vector2.hpp"

game::Game::Game()
    : title_("Zelda Clone"), window_(raylib::Window(kWidth, kHeight, title_)) {
  SetTargetFPS(60);
  textures_.emplace(Landscape::Earth, new raylib::Texture("res/img/earth.png"));
  camera_.SetZoom(1.0f);
}

bool game::Game::IsRunning() { return !window_.ShouldClose(); }

void game::Game::Draw() {
  BeginDrawing();
  {
    window_.ClearBackground(RAYWHITE);
    camera_.BeginMode();
    {
      textures_[Landscape::Earth]->Draw(50, 50);
      DrawCircle(100, 100, 50, YELLOW);
    }
    camera_.EndMode();
  }
  EndDrawing();
}

game::Game& game::Game::Next() { return *this; }

game::Game& game::Game::Poll() {
  if (IsKeyPressed(KEY_ESCAPE)) {
    window_.Close();
  }
  if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
    Vector2 delta = GetMouseDelta();
    delta = Vector2Scale(delta, -1.0f / camera_.zoom);

    camera_.target = Vector2Add(camera_.target, delta);
  }

  return *this;
}
