#include <stdbool.h>
#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>

#include "dungeon.h"
#include "slist.h"
#include "tile.h"

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

  // Initialize .png image loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    fprintf(stderr, "Unable to init SDL_image: %s\n", IMG_GetError());
    SDL_Quit();
    return 1;
  }

  // Ensure we free SDL and IMG
  atexit(cleanup);

  // Create a game window
  SDL_Window *window = SDL_CreateWindow("Roguelike", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, windowWidth,
                                        windowHeight, SDL_WINDOW_SHOWN);
  if (!window) {
    fprintf(stderr, "Window could not be created: %s\n", SDL_GetError());
    return 1;
  }

  // Create a hardware accelerated renderer
  SDL_Renderer *renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    fprintf(stderr, "Renderer could not be created: %s\n", SDL_GetError());
    return 1;
  }

  // Load game textures
  SList *textures = SList_Create();
  SDL_Texture *dungeonTiles = loadTexture(renderer, "./assets/dungeon.png");
  SList_Add(textures, dungeonTiles);

  // Generate the dungeon
  RL_Dungeon *dungeon = RL_Dungeon_Create(64);
  RL_Dungeon_Print(dungeon);

  bool quit = false;
  SDL_Event evt;
  while (!quit) {
    // Event loop
    while (SDL_PollEvent(&evt) != 0) {
      if (evt.type == SDL_QUIT) {
        quit = true;
      }
    }

    // Render loop
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);
    for (int i = 0; i < (int)ceilf((float)windowWidth / 16); i++) {
      for (int j = 0; j < (int)ceilf((float)windowHeight / 16); j++) {
        if (i >= 0 && i < dungeon->size && j >= 0 && j < dungeon->size) {
          RL_Tile *tile = RL_Dungeon_TileAt(dungeon, i, j);
          SDL_Rect dst = {i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE};
          SDL_RenderCopy(renderer, dungeonTiles, &tile->src, &dst);
        }
      }
    }

    SDL_RenderPresent(renderer);
  }

  // Free dungeon
  RL_Dungeon_Free(dungeon);

  // Free textures
  SList_ForEach(textures, SDL_DestroyTexture(current->data));
  SList_Free(textures);

  return 0;
}
