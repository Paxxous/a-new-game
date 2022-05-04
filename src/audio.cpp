#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

#include "audio.hpp"


Music::Music(const char* audioPath) {

  // Load up the music
  theMusic = Mix_LoadMUS(audioPath);
  if (theMusic == NULL) {
    std::cout << "There was trouble loading the audio :(\n" << Mix_GetError() << "\n";
  }
}

void Music::play(int loop) {
  // Play the music
  Mix_PlayMusic(theMusic, loop);
}