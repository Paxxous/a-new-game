#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <iostream>


class Music {
  public:
    Music(const char* audioPath);

    // Functionality to the Music object
    void play(int loop);

  private:
    Mix_Music* theMusic;
};
