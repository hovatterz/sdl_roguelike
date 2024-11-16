#include "tile.h"
#include "rand.c"

SDL_Rect RL_TileType_Rect(RL_TileType type) {
  SDL_Rect rect = {0, 0, TILE_SIZE, TILE_SIZE};
  switch (type) {
  case RL_TileType_Floor:
    rect.x = rand_range(6, 9) * TILE_SIZE;
    rect.y = rand_range(0, 2) * TILE_SIZE;
    break;

  case RL_TileType_Wall:
    rect.x = TILE_SIZE;
    rect.y = 0;
    break;
  }

  return rect;
}

RL_Tile *RL_Tile_Create(RL_TileType type) {
  RL_Tile *tile = malloc(sizeof(RL_Tile));
  if (!tile) {
    return NULL;
  }

  tile->type = type;
  tile->src = RL_TileType_Rect(type);
  return tile;
}

void RL_Tile_Free(RL_Tile *tile) { free(tile); }
