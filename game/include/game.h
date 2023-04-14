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
  int16_t x_ = 0;
  int16_t y_ = 0;
};

class Cell {
 private:
  Landscape land_;
  bool canPass_ = true;
};

class World {
 private:
  std::vector<Cell> cells_;

 public:
  World();
  bool CanMoveInside(Position pos);
};

class Item {
  int16_t id_ = 0;
};

class Enemy {
  int16_t health_ = 0;
  int16_t drop_ = 0;
  float speed_ = 0.0f;
};

class Hero {
  int16_t health_ = 0;
  int16_t arrows_ = 0;
  int16_t bombs_ = 0;
  std::vector<Item> inventory_;
  float speed_ = 0.0f;
};

class Npc {
  int16_t health_ = 0;
  int16_t drop_ = 0;
  float speed_ = 0.0f;
};

class Camera {
  Position pos_;
  int16_t width_{kWidth};
  int16_t height_{kHeight};
};

class Game {
 private:
  std::string title_{"Zelda Clone"};
  raylib::Window window_{kWidth, kHeight, title_};
  Camera camera_;
  World World_;
  std::vector<Npc> npcs_;
  std::vector<Enemy> enemies_;
  std::map<Landscape, raylib::Texture*> textures_;
  Hero hero_;

 public:
  Game();
  ~Game();
  Game& Next();
  Game& Poll();
  void Draw();
  bool IsRunning();
};

}  // namespace game

#endif  // GAME_GAMEH