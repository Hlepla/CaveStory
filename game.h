#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "level.h"

class Graphics;

class Game
{

 private:

  void gameloop();
  void draw(Graphics &graphics);
  void update(float elapsedTime);

  Player _player;

  Level _level;
  
 public:
  
  Game() ;
  ~Game(); 


};

#endif
