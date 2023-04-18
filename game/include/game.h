#include <cstddef>
#include <cstdint>

#if !defined(GAME_GAMEH)
#define GAME_GAMEH

#include <array>
#include <map>
#include <memory>
#include <raylib-cpp.hpp>
#include <string>
#include <vector>

namespace game {
constexpr int16_t kHeight = 720;
constexpr int16_t kWidth = 1280;

template <class T, size_t width, size_t height>
using Matrix2D = std::array<std::array<T, height>, width>;

enum class Landscape { Empty, Earth, Water, Rock, Bush };

class Cell {
 private:
  Landscape land_;
  bool canPass_;
};

class World {
 private:
  std::vector<Cell> cells_;

 public:
  World();
  bool CanMoveInside(Position pos);
  bool CanMoveInside(raylib::Vector2 pos);
};

class Item {
  int16_t id_;
};

class Enemy {
  int16_t health_;
  int16_t drop_;
  float speed_;
};

class Hero {
  int16_t health_;
  int16_t arrows_;
  int16_t bombs_;
  std::vector<Item> inventory_;
  float speed_;
};

class Npc {
  int16_t health_;
  int16_t drop_;
  float speed_;
};

class Game {
 private:
  std::string title_;
  raylib::Window window_;
  World World_;
  raylib::Camera2D camera_;
  std::vector<Npc> npcs_;
  std::vector<Enemy> enemies_;
  std::map<Landscape, std::shared_ptr<raylib::Texture>> textures_;
  Hero hero_;

 public:
  Game();
  Game& Next();
  Game& Poll();
  void Draw();
  bool IsRunning();
};

}  // namespace game

#endif  // GAME_GAMEH
