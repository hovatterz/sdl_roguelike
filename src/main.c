#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>

const int windowWidth = 800, windowHeight = 600;

int main(int argc, char **argv) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
    return 1;
  }

  atexit(SDL_Quit);

  SDL_Window *window = SDL_CreateWindow("Roguelike", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, windowWidth,
                                        windowHeight, SDL_WINDOW_SHOWN);
  if (!window) {
    fprintf(stderr, "Window could not be created: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    fprintf(stderr, "Renderer could not be created: %s\n", SDL_GetError());
    return 1;
  }

  bool quit = false;
  SDL_Event evt;
  while (!quit) {
    while (SDL_PollEvent(&evt) != 0) {
      if (evt.type == SDL_QUIT) {
        quit = true;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  return 0;
}
