#ifndef MAP_H
#define MAP_H

#include "player.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

void draw_minimap(Player *player);

void draw_2d_map(Player *player);

#endif