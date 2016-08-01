/* input.h
   

 */



#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <map>

class Input
{
 private:
  
  std::map<SDL_Scancode,bool> _heldKeys; // values of this are used to represent keyboard keys
  std::map<SDL_Scancode,bool> _pressedKeys;
  std::map<SDL_Scancode,bool> _releasedKeys;

 public:

  void beginNewFrame();
  void keyUpEvent(const SDL_Event& event);
  void keyDownEvent(const SDL_Event& event);
  
  bool wasKeyPressed(SDL_Scancode key);
  bool wasKeyReleased(SDL_Scancode key);
  bool isKeyHeld(SDL_Scancode key);

  

};

#endif
