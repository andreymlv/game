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

template <class T, size_t Width, size_t Height>
using Matrix2D = std::array<std::array<T, Height>, Width>;

enum class Landscape { kEmpty, kEarth, kWater, kRock, kBush };

class Cell {
 public:
  Cell();
  explicit Cell(Landscape land);

 private:
  Landscape land_;
  bool canPass_;
};

class World {
 public:
  bool CanMoveInside(raylib::Vector2 pos);
  void FillWithEarth();
  template <size_t Width, size_t Height>
  Matrix2D<Cell, Width, Height> Project(raylib::Camera2D cam);

 private:
  Matrix2D<Cell, kWidth, kHeight> cells_;
};

class Item {
 private:
  int16_t id_;
};

class Enemy {
 private:
  int16_t health_;
  int16_t drop_;
  float speed_;
};

class Hero {
 private:
  int16_t health_;
  int16_t arrows_;
  int16_t bombs_;
  std::vector<Item> inventory_;
  float speed_;
};

class Npc {
 private:
  int16_t health_;
  int16_t drop_;
  float speed_;
};

class Game {
 public:
  Game();
  Game& Next();
  Game& Poll();
  void Draw();
  bool IsRunning();

 private:
  std::string title_;
  raylib::Window window_;
  raylib::Camera2D camera_;
  World world_;
  std::vector<Npc> npcs_;
  std::vector<Enemy> enemies_;
  std::map<Landscape, std::shared_ptr<raylib::Texture>> textures_;
  Hero hero_;
};

}  // namespace game

#endif  // GAME_GAMEH
