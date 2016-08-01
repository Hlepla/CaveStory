/*input.cpp
  the implementation of the input class
  keeps track of our keyboard state
*/

#include "input.h"

void Input::beginNewFrame() // this function gets called at the beginning of each new frame (to reset keys that are no longer relevant)
{
  this->_pressedKeys.clear();
  this->_releasedKeys.clear();

}

void Input::keyDownEvent(const SDL_Event& event) // this gets called when a key gets pressed 
{
  this->_pressedKeys[event.key.keysym.scancode] = true ;
  this->_heldKeys[event.key.keysym.scancode] = true ;
  

}

void Input::keyUpEvent(const SDL_Event& event) // this gets called when a key is released
{
  this->_releasedKeys[event.key.keysym.scancode] = true ;
  this->_heldKeys[event.key.keysym.scancode] = false ;

  
}

bool Input::wasKeyPressed(SDL_Scancode key) // Check if a certain key was pressed during the current frame 
{
  return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) // Check if a certian key was released during the current frame
{
  return this->_releasedKeys[key] ;

}

bool Input::isKeyHeld(SDL_Scancode key) // Check if a certian key is currently held during the current frame
{
  return this->_heldKeys[key];

}
