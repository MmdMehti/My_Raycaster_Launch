#ifndef PLAYER_H
#define PLAYER_H

#include "vector.h"

typedef struct {
    Vec2 pos;    //player position
    Vec2 dir;    //player dirction
    Vec2 plane;
} Player;

void init_player(Player* p);

void update_player(Player* p, float dt, int map[20][20]);

#endif