#include <stdlib.h>
#include <math.h>
#include "raylib.h"

#define GRID_W 128
#define GRID_H 64

#define WORM_MAX_LEN 32

typedef struct
{
    float x[32];
    float y[32];
    int len;

    float dx;
    float dy;

} Worm;

int main(void)
{
    int grid[GRID_W][GRID_H] = {0};

    Worm worm = {.len=24};

    for(int i=0; i<GRID_W; i++){
        for(int j=0; j<GRID_H; j++){
            grid[i][j] = rand()%255;
        }
    }

    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Worm game");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float velx = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
        float vely = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);

        int speed = 3;
        worm.dx = velx*speed;
        worm.dy = vely*speed;

        float seg_dist = 32.5f; // distância desejada entre segmentos (em células)

        // move a cabeça normalmente
        worm.x[0] += worm.dx;
        worm.y[0] += worm.dy;

        // arrasta o resto com constraint de distância
        for (int seg = 1; seg < worm.len; seg++)
        {
            float dx = worm.x[seg - 1] - worm.x[seg];
            float dy = worm.y[seg - 1] - worm.y[seg];
            float dist = sqrtf(dx * dx + dy * dy);

            if (dist > seg_dist)
            {
                float ratio = (dist - seg_dist) / dist;
                worm.x[seg] += dx * ratio;
                worm.y[seg] += dy * ratio;
            }
        }


        BeginDrawing();
            ClearBackground(RAYWHITE);

            int size = 24;
            for(int i=0; i<GRID_W; i++){
                for(int j=0; j<GRID_H; j++){
                    DrawRectangle(i*size, j*size, size, size, (Color){grid[i][j], 0, 0, 255});
                }
            }

            for(int seg=0; seg<worm.len; seg++){
                DrawCircle(worm.x[seg], worm.y[seg], 16, (Color){(float)seg/(float)worm.len * 255, 200, 128, 255});
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
