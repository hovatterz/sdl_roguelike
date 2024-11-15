#include <stdbool.h>
#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>

#include "slist.h"

const int windowWidth = 800, windowHeight = 600;

SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *path) {
  SDL_Texture *tex = NULL;

  // Load image at specified path
  SDL_Surface *image = IMG_Load(path);
  if (!image) {
    fprintf(stderr, "Failed to load image: %s\n", IMG_GetError());
  } else {
    // Create texture from surface pixels
    tex = SDL_CreateTextureFromSurface(renderer, image);
    if (!tex) {
      fprintf(stderr, "Failed to create texture from %s: %s\n", path,
              SDL_GetError());
    }
    SDL_FreeSurface(image);
  }

  return tex;
}

void cleanup() {
  IMG_Quit();
  SDL_Quit();
}

int main(int argc, char **argv) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
    return 1;
  }

  atexit(cleanup);

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

  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    fprintf(stderr, "Unable to init SDL_image: %s\n", IMG_GetError());
    return 1;
  }

  SList *textures = SList_Create();
  SDL_Texture *dungeonTiles = loadTexture(renderer, "./assets/dungeon.png");
  SList_Add(textures, dungeonTiles);

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
    SDL_RenderCopy(renderer, dungeonTiles, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  // Free textures
  SList_Node *current = textures->head;
  while (current != NULL) {
    SDL_Texture *texture = current->data;
    SDL_DestroyTexture(texture);

    current = current->next;
  }

  SList_Destroy(textures);

  return 0;
}
