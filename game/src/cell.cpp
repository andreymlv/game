#include "game.h"

game::Cell::Cell(Landscape land) : canPass_(true) { land_ = land; }
game::Cell::Cell() : land_(Landscape::kEmpty), canPass_(true) {}
