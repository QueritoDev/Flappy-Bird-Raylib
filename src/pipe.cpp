#include "../include/pipe.h"
#include "../include/constants.h"
#include <raylib.h>

void InitPipes(PipeManager& manager){
    manager.texture = LoadTexture("../assets/images/pipe.png");

    for(int i = 0; i< MAX_PIPES; ++i) {
        manager.pipes[i].pipeScroll = -60;
        manager.pipes[i].position.x = VIRTUAL_WIDTH + (i * PIPE_SPACING);
        manager.pipes[i].position.y = GetRandomValue(VIRTUAL_HEIGHT / 2, VIRTUAL_HEIGHT - 10);
    }

}

void UpdatePipes(PipeManager& manager, float dt) {
    for (int i = 0; i < MAX_PIPES; ++i) {
        manager.pipes[i].position.x += manager.pipes[i].pipeScroll * dt;

        if(manager.pipes[i].position.x <= -manager.texture.width){
            float rightMostX = 0;
            for (int j = 0; j < MAX_PIPES; j++) {
                if (manager.pipes[j].position.x > rightMostX) {
                    rightMostX = manager.pipes[j].position.x;
                }
            }
            manager.pipes[i].position.x = rightMostX + PIPE_SPACING;
            manager.pipes[i].position.y = GetRandomValue(VIRTUAL_HEIGHT / 2, VIRTUAL_HEIGHT - 18);
        }
    }
}

void DrawPipes(const PipeManager& manager) {
    for (int i = 0; i < MAX_PIPES; ++i) {
        if(i<2){
            DrawTextureV(manager.texture, manager.pipes[i].position, WHITE);
        }else{
            DrawTexture(manager.texture, manager.pipes[i].position.x, -manager.pipes[i].position.y, WHITE);
        }


    }
}

void UnloadPipes(PipeManager& manager) {
    UnloadTexture(manager.texture);
}
