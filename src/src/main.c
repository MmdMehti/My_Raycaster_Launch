#include "raylib.h"
#include "player.h"
#include "map.h"
#include "raycast.h"
#include "game.h"

int main(void) {

    InitWindow(800, 640, "Raycasting");

    SetTargetFPS(60);

    Player player;

    init_player(&player);

    GameState CurrentMode = Play_Mode;

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        update_player(&player, dt, world_map);

        if (IsKeyPressed(KEY_M)) {
            if (CurrentMode == Play_Mode)
                CurrentMode = Edit_Mode;
            else
                CurrentMode = Play_Mode;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (CurrentMode == Play_Mode) {
            cast_rays(&player);

            draw_minimap(&player);
        } else {
            draw_2d_map(&player);

            int tile = 32;

            int mapX = GetMouseX() / tile;
            int mapY = GetMouseY() / tile;

            if (mapX > 0 && mapX < MAP_WIDTH-1 && mapY > 0 && mapY < MAP_HEIGHT-1) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    world_map[mapY][mapX] = 1;

                if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
                    world_map[mapY][mapX] = 0;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}