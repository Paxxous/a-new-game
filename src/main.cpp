#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_mixer.h>

#include "renderWindow.hpp"
#include "Entity.hpp"
#include "Audio.hpp"



// The main function
int main( /* (for cross platform stuff) */ int argc, char* argv[]) {

  // Just for some useful input if an error is recieved
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cout << "You got yourself a problem there homie...\n" << SDL_GetError() << "\n"; 
  }

  // Initialize the music 44100, MIX_DEFAULT_FORMAT, 2, 2048
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    std::cout << "SDL_mixer could not initialize D:\n" << Mix_GetError() << "\n";
  }


  // Init the background music
  Music brodyBackgroundMusic("res/sfx/brodyquest.wav");
  brodyBackgroundMusic.play(-1);


  // Create a window
  RenderWindow window("BEst", 1280, 720);

  // Create a grass texture
  SDL_Texture* brodyTexture = window.loadTexture("res/gfx/brdoy.png");
  SDL_Texture* yello = window.loadTexture("res/gfx/h.png");

  // Create the brody entity
  Entity brody(0, 96, brodyTexture);


  // Create multile yellows
  Entity yellows[10] = {
    Entity(0, 128, yello),
    Entity(32, 128, yello),
    Entity(64, 128, yello),
    Entity(96, 128, yello),
    Entity(128, 128, yello),
    Entity(160, 128, yello),
    Entity(192, 128, yello),
    Entity(224, 128, yello),
    Entity(256, 128, yello),
    Entity(288, 128, yello),
  };


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

      // Reset the window and set the color
      window.clear();
      window.windowColor(255, 255, 255, 255);


      // Render all of the yellows
      for (int i = 0; i < 10; i++) {
        window.render(yellows[i]);
      }

      // Render Brody
      window.render(brody);

      // Display it all
      window.display();
    }
  }

  // Quit and deallocate everything
  window.cleanup();
  SDL_Quit();


  return 0;
}