#include "map.h"
#include "raylib.h"

int world_map[MAP_WIDTH][MAP_HEIGHT] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void draw_minimap(Player *player) {
    int tile = 10;
    float dirLength = 1.0f;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Color c = world_map[y][x] ? DARKGREEN : GRAY;
            DrawRectangle(x * tile, y * tile, tile, tile, c);
        }
    }

    float px = player->pos.x * tile;
    float py = player->pos.y * tile;

    DrawCircle(px, py, 3, RED);

    DrawLine(
        px,
        py,
        px + player->dir.x * tile * dirLength,
        py + player->dir.y * tile * dirLength,
        RED
    );
}

void draw_2d_map(Player *player) {
    int tile = 32;
    float dirLength = 0.5f;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Color c = world_map[y][x] ? DARKGREEN : GRAY;
            DrawRectangle(x * tile, y * tile, tile, tile, c);
            DrawRectangleLines(x * tile, y * tile, tile, tile, RAYWHITE);
        }
    }

    DrawCircle(player->pos.x * tile, player->pos.y * tile, 5, RED);

    float px = player->pos.x * tile;
    float py = player->pos.y * tile;

    DrawLine(
        px,
        py,
        px + player->dir.x * tile * dirLength,
        py + player->dir.y * tile * dirLength,
        RED
    );
}