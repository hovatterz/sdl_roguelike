#include <stdio.h>
#include <stdlib.h>

#include "dungeon.h"

RL_Dungeon *RL_Dungeon_Create(unsigned int size) {
  RL_Dungeon *dungeon =
      malloc(sizeof(RL_Dungeon) + sizeof(RL_Tile *) * size * size);
  if (!dungeon) {
    return NULL;
  }

  dungeon->size = size;
  for (int i = 0; i < size * size; i++) {
    dungeon->tiles[i] = RL_Tile_Create(RL_TileType_Floor);
  }

  return dungeon;
}

void RL_Dungeon_Generate(RL_Dungeon *dungeon) {}

RL_Tile *RL_Dungeon_TileAt(RL_Dungeon *dungeon, unsigned int x,
                           unsigned int y) {
  return dungeon->tiles[x * dungeon->size + y];
}

void RL_Dungeon_Print(RL_Dungeon *dungeon) {
  for (int i = 0; i < dungeon->size; i++) {
    for (int j = 0; j < dungeon->size; j++) {
      switch (RL_Dungeon_TileAt(dungeon, i, j)->type) {
      case RL_TileType_Floor:
        fprintf(stdout, ".");
        break;

      case RL_TileType_Wall:
        fprintf(stdout, "#");
        break;

      default:
        fprintf(stdout, "?");
        break;
      }
    }

    printf("\n");
  }
}

void RL_Dungeon_Free(RL_Dungeon *dungeon) {
  for (int i = 0; i < dungeon->size * dungeon->size; i++) {
    RL_Tile_Free(dungeon->tiles[i]);
  }

  free(dungeon);
}
