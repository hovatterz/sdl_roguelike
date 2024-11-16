#ifndef TILE_H_
#define TILE_H_

#include <SDL.h>

#define TILE_SIZE 16
#define TILE_COLS 10
#define TILE_ROWS 10

typedef enum rl_tiletype { RL_TileType_Floor, RL_TileType_Wall } RL_TileType;

SDL_Rect RL_TileType_Rect(RL_TileType type);

typedef struct rl_tile {
  RL_TileType type;
  SDL_Rect src;
} RL_Tile;

RL_Tile *RL_Tile_Create(RL_TileType type);
void RL_Tile_Free(RL_Tile *tile);

#endif
