#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "global.h"

class Graphics;

class Player : public AnimatedSprite {

 private:

  float _dx , _dy ;
  Direction _facing ;

 public:

  Player();
  Player(Graphics &graphics, float x , float y);

  void draw(Graphics &graphics);
  void update(float elapsedTime);

  void moveLeft(); // moves the player left by -dx
  
  void moveRight(); // moves the player right by dx
  
  void stopMoving(); // stops moving the player

   virtual void animationDone(std::string currentAnimation) ;
   virtual void setupAnimations() ;
  
  

};




#endif
