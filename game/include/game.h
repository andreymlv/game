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

 public:
  Cell();
  Cell(Landscape land);
};

class World {
 private:
  Matrix2D<Cell, kWidth, kHeight> cells_;

 public:
  bool CanMoveInside(raylib::Vector2 pos);
  void FillWithEarth();

  template <size_t width, size_t height>
  Matrix2D<Cell, width, height> Project(raylib::Camera2D cam);
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
  raylib::Camera2D camera_;
  World world_;
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
