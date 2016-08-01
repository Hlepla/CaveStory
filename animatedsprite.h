/* AnimatedSprite.h
   Holds logic for animating sprites
  
 */

#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "graphics.h"
#include "global.h"
#include "sprite.h"

class Graphics;


class AnimatedSprite : public Sprite
{
 private:

  std::map<std::string , std::vector<SDL_Rect> > _animations ;

  std::map<std::string,Vector2> _offsets;

  int _frameIndex;
  double _timeElapsed ;
  bool _visible;
  
  
 public:
  
  AnimatedSprite();
  AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int SourceY, int width, int height, float posX, float posY, float timeToUpdate);
  
  
  void playAnimation(std::string animation , bool once = false) ; // Plays the animation provided if its not already playing
  
  void update(int elapsedTime); // Updates the animated sprite (timer)
  
  void draw(Graphics &graphics, int x, int y); // Draws sprite to the screen

 protected:

  double _timeToUpdate ;
  bool _currentAnimationOnce ;
  std::string _currentAnimation;

  void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset); // Adds an animation to the map of animations for the sprite

  void resetAnimations(); // Resets all animations associated with a sprite

  void stopAnimation(); // stops current animation

  void setVisible(bool visible) ; // changes the visibility of the animated sprite

  virtual void animationDone(std::string currentAnimation) = 0  ; // Logic that happens when an animation ends , required function. Setting it = 0 makes it a pure virtual function

  virtual void setupAnimations() = 0  ; //  a required function that sets up all animations for a sprite. Setting it = 0 makes it a pure virutal function
  
};


#endif
