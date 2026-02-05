#include "player.h"
#include "raylib.h"
#include <math.h>

#define MOVE_SPEED 5.0f
#define ROT_SPEED  3.0f

void init_player(Player *p) {
    
    p->pos.x = 3.5f;
    p->pos.y = 3.5f;

    p->dir.x = -1.0f;
    p->dir.y = 0.0f;

    p->plane.x = 0.0f;
    p->plane.y = 0.66f;

}

void update_player(Player *p, float dt, int map[20][20]) {
    
    float move = MOVE_SPEED * dt;
    float rot  = ROT_SPEED * dt;

    if (IsKeyDown(KEY_W)) {
        
        float nx = p->pos.x + p->dir.x * move;
        float ny = p->pos.y + p->dir.y * move;

        if (map[(int)p->pos.y][(int)nx] == 0)
            p->pos.x = nx;

        if (map[(int)ny][(int)p->pos.x] == 0)
            p->pos.y = ny;
    }

    if (IsKeyDown(KEY_S)) {

        float nx = p->pos.x - p->dir.x * move;
        float ny = p->pos.y - p->dir.y * move;

        if (map[(int)p->pos.y][(int)nx] == 0)
            p->pos.x = nx;

        if (map[(int)ny][(int)p->pos.x] == 0)
            p->pos.y = ny;
    }

    if (IsKeyDown(KEY_A)) {

        float nx = p->pos.x + p->dir.y * move;
        float ny = p->pos.y - p->dir.x * move;

        if (map[(int)p->pos.y][(int)nx] == 0)
            p->pos.x = nx;

        if (map[(int)ny][(int)p->pos.x] == 0)
            p->pos.y = ny;
    }

    if (IsKeyDown(KEY_D)) {

        float nx = p->pos.x - p->dir.y * move;
        float ny = p->pos.y + p->dir.x * move;

        if (map[(int)p->pos.y][(int)nx] == 0)
            p->pos.x = nx;

        if (map[(int)ny][(int)p->pos.x] == 0)
            p->pos.y = ny;
    }

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT)) {

        float angle = IsKeyDown(KEY_RIGHT) ? rot : -rot;

        float oldDirX = p->dir.x;

        p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
        p->dir.y = oldDirX * sin(angle) + p->dir.y * cos(angle);

        float oldPlaneX = p->plane.x;

        p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
        p->plane.y = oldPlaneX * sin(angle) + p->plane.y * cos(angle);
    }
}