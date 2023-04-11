#include <string>
namespace game {
constexpr int16_t kHeight = 500;
constexpr int16_t kWidth = 500;

class Position {
  int16_t x_;
  int16_t y_;
};

class Cell {
  std::string texture_;
  bool canPass_;
};

class World {
  Cell cells_[kWidth][kHeight];
};

class Item {
  int16_t id_;
};

class Enemy {
  int16_t health_;
  float speed_;
  int16_t drop_;
};

class Hero {
  int16_t health_;
  int16_t arrows_;
  int16_t bombs_;
  Item inventory_[10];
  float speed_;
};

class Npc {
  int16_t health_;
  int16_t drop_;
  float speed_;
};

class Cam {
  Position pos_;
  int16_t width_;
  int16_t height_;
};

class Window {
private:
  int16_t width_;
  int16_t height_;
public:
  Window(int16_t width, int16_t height);
  ~Window();
};

class Game {
 private:
  std::string title_;

 public:
  Game();
  void run();
};

}  // namespace game
