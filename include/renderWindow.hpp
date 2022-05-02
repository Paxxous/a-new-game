#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "renderWindow.hpp"

// Just some general settings
const int WIDTH = 500, HEIGHT = 500;

// SDL_CreateWindow("Men liker 300", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
class RenderWindow {
  public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_file_path);

    void cleanup();
    void clear();
    void render(Entity& p_entity);
    void display();
    void windowColor(int r, int g, int b, int a);

  private:
    // Get the address of the window and renderer.
    SDL_Window *window;
    SDL_Renderer* renderer;
};