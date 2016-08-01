

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{

 private:
  SDL_Window* _window ;
  SDL_Renderer* _renderer ;

  std::map<std::string, SDL_Surface*> _spriteSheets;
  
 public:
  
  Graphics();
  ~Graphics();

  SDL_Surface* loadImage(const std::string &filePath); // SDL_Surface, loads an image into the _spriteSheets map if it doesnt already exist. each image will only be loaded once.
  
  
  void blitSurfacer(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle); // draws a texture to a certian part of the screen


  void flip(); // renders everything to the screen

  void clear(); // clears the screen


  SDL_Renderer* getRenderer() const; // return the renderer 
  
};

#endif 
