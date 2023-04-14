#include "game.h"

int main(void) {
  game::Game game;
  while (game.IsRunning()) {
    game = game.Poll();
    game = game.Next();
    game.Draw();
  }
  return 0;
}