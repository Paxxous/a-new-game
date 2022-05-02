#include <SDL2/SDL.h>
#include <iostream>

#include "renderWindow.hpp"
#include "Entity.hpp"

// The main function
int main( /* (for cross platform stuff) */ int argc, char* argv[]) {

  // Just for some useful input if an error is recieved
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cout << "You got yourself a problem there homie...\n" << SDL_GetError() << "\n"; 
  }

  // Create a window
  RenderWindow window("BEst", 1280, 720);

  // Create a grass texture
  SDL_Texture* brodyTexture = window.loadTexture("../res/gfx/brdoy.png");
  Entity brody(0, 0, brodyTexture);

  // Create an event object
  SDL_Event e;

  // The value that controls the main game loop
  bool running = true;
  while (running) {
    while (SDL_PollEvent(&e)) {
      // If the user kills the window
      if (e.type == SDL_QUIT) {
        running = false;
      }

      window.clear();
      window.render(brody);
      window.display();

      // std::cout << e.type << "\n";
    }
  }

  // Quit and deallocate everything
  window.cleanup();
  SDL_Quit();


  return 0;
}