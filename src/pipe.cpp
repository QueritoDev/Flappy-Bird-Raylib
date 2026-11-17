#include <raylib.h>
#include "../include/pipe.h"
#include "../include/constants.h"

void initPipe(Pipe& pipe) {
    pipe.position.x = VIRTUAL_WIDTH;
    pipe.tex = LoadTexture("../assets/images/pipe.png");
    pipe.pipeScroll = -60;
    pipe.position.y = GetRandomValue(VIRTUAL_HEIGHT / 4, VIRTUAL_HEIGHT - 10);

    pipe.width = pipe.tex.width;
}

void updatePipe(Pipe& pipe, float dt) {
    pipe.position.x = pipe.position.x + pipe.pipeScroll * dt;


}

void drawPipe(const Pipe& pipe) {
    DrawTexture(pipe.tex, pipe.position.x, pipe.position.y, WHITE);
}

void unloadPipe(Pipe& pipe) {

}
