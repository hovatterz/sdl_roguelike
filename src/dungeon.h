#ifndef DUNGEON_H_
#define DUNGEON_H_

#include "tile.h"

typedef struct rl_dungeon {
  unsigned int size;
  RL_Tile *tiles[];
} RL_Dungeon;

RL_Dungeon *RL_Dungeon_Create(unsigned int size);
void RL_Dungeon_Generate(RL_Dungeon *dungeon);
RL_Tile *RL_Dungeon_TileAt(RL_Dungeon *dungeon, unsigned int x, unsigned int y);
void RL_Dungeon_Print(RL_Dungeon *dungeon);
void RL_Dungeon_Free(RL_Dungeon *dungeon);

#endif
