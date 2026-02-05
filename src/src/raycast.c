#include "raycast.h"
#include "map.h"
#include "raylib.h"
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640

void cast_rays(Player *player) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        float cameraX = 1.0f - 2.0f * x / SCREEN_WIDTH;

        float rayDirX = player->dir.x + player->plane.x * cameraX;
        float rayDirY = player->dir.y + player->plane.y * cameraX;

        int mapX = (int)player->pos.x;
        int mapY = (int)player->pos.y;

        float deltaDistX = fabsf(1.0f / rayDirX);
        float deltaDistY = fabsf(1.0f / rayDirY);

        float sideDistX, sideDistY;
        int stepX, stepY;
        int hit = 0;
        int side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (player->pos.x - mapX) * deltaDistX;
        }
        else {
            stepX = 1;
            sideDistX = (mapX + 1.0f - player->pos.x) * deltaDistX;
        }

        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (player->pos.y - mapY) * deltaDistY;
        }
        else {
            stepY = 1;
            sideDistY = (mapY + 1.0f - player->pos.y) * deltaDistY;
        }

        while (!hit) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            if (world_map[mapY][mapX] > 0)
                hit = 1;
        }

        float perpWallDist;
        if (side == 0)
            perpWallDist = (mapX - player->pos.x + (1 - stepX) / 2.0f) / rayDirX;
        else
            perpWallDist = (mapY - player->pos.y + (1 - stepY) / 2.0f) / rayDirY;

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;

        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

        DrawRectangle(x, 0, 1, drawStart, SKYBLUE);

        float shade = 1.0f / (1.0f + perpWallDist * 0.1f);
        if (side == 1)
            shade *= 0.6f;

        unsigned char green = (unsigned char)(200 * shade);
        Color wallColor = (Color){ 0, green, 0, 255 };

        DrawRectangle(x, drawStart, 1, drawEnd - drawStart, wallColor);

        DrawRectangle(x, drawEnd, 1, SCREEN_HEIGHT - drawEnd, GRAY);
    }
}