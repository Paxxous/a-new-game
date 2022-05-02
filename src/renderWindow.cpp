#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "renderWindow.hpp"
#include "Entity.hpp"

// Create a window
RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h):window(NULL), renderer(NULL) {
  window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);

  if (window == NULL) {
    std::cout << "Window had some trouble initializing...\n" << SDL_GetError() << "\n";
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

// Load textures
SDL_Texture* RenderWindow::loadTexture(const char* p_file_path) {
  SDL_Texture* texture;

  texture = IMG_LoadTexture(renderer, p_file_path);

  if (texture == NULL) {
    std::cout << "BRO SOMETHING WRONG HAPPENED LOADING YOUR IMAGE LMAOOOOOO\n" << SDL_GetError() << "\n";
  }

  return texture;
}

// Cleanup the window
void RenderWindow::cleanup() {
  SDL_DestroyWindow(window);
}

// Clear the window
void RenderWindow::clear() {
  SDL_RenderClear(renderer);
}

// Render images
void RenderWindow::render(Entity& p_entity) {
  SDL_Rect src;
  src.x = p_entity.getCurrentFrame().x;
  src.y = p_entity.getCurrentFrame().y;
  src.w = p_entity.getCurrentFrame().w;
  src.h = p_entity.getCurrentFrame().h;

  SDL_Rect dst;
  dst.x = p_entity.getX();
  dst.y = p_entity.getY();
  dst.w = p_entity.getCurrentFrame().w * 10;
  dst.h = p_entity.getCurrentFrame().h * 10;

  SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

// Display everything
void RenderWindow::display() {
  SDL_RenderPresent(renderer);
}

// Restart pc soon...