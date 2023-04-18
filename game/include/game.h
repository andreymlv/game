#if !defined(GAME_GAMEH)
#define GAME_GAMEH

#include <map>
#include <memory>
#include <raylib-cpp.hpp>
#include <string>
#include <vector>

namespace game {
constexpr int16_t kHeight = 720;
constexpr int16_t kWidth = 1280;

enum class Landscape { Earth, Water, Rock, Bush };

class Position {
  int16_t x_;
  int16_t y_;
};

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

class Camera {
 private:
  Position pos_;
  int16_t width_;
  int16_t height_;

 public:
  Camera();
};

class Game {
 private:
  std::string title_;
  raylib::Window window_{kWidth, kHeight, title_};
  Camera camera_;
  World World_;
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
