#include "../include/pipe.h"
#include "../include/constants.h"
#include <raylib.h>

void InitPipe(Pipe& pipe) {
    pipe.texture = LoadTexture("../assets/images/pipe.png");
    pipe.pipeScroll = -60;
    float posX = VIRTUAL_WIDTH;
    float posY = GetRandomValue(VIRTUAL_HEIGHT/2, VIRTUAL_HEIGHT - 10);
    pipe.position = {posX, posY};
}

void DrawPipe(const Pipe& pipe) {
    DrawTextureV(pipe.texture, pipe.position, WHITE);
}

void UpdatePipe(Pipe& pipe, float dt) {
    pipe.position.x += pipe.pipeScroll * dt;
    if(pipe.position.x<=0){
        ResetPipe(pipe);
    }
}

void ResetPipe(Pipe& pipe) {
    InitPipe(pipe);
}

void UnloadPipe(Pipe& pipe) {
    UnloadTexture(pipe.texture);

}
