#include <raylib.h>
#include "../include/pipe.h"
#include "../include/constants.h"

void initPipe(Pipe& pipe, Texture2D tex) {
    pipe.position.x = VIRTUAL_WIDTH;
    pipe.tex = tex;
    pipe.pipeScroll = -60;
    pipe.position.y = GetRandomValue(VIRTUAL_HEIGHT / 2, VIRTUAL_HEIGHT - 10);

    pipe.width = pipe.tex.width;
}

void updatePipe(Pipe& pipe, float dt) {
    pipe.position.x = pipe.position.x + pipe.pipeScroll * dt;

}

void drawPipe(const Pipe& pipe) {
    DrawTexture(pipe.tex, pipe.position.x, pipe.position.y, WHITE);

    Rectangle source = { 0.0f, 0.0f, (float)pipe.tex.width, (float)-pipe.tex.height };

    Rectangle dest = { pipe.position.x, pipe.position.y - VIRTUAL_HEIGHT, (float)pipe.tex.width, (float)pipe.tex.height-100};

    DrawTexturePro(pipe.tex, source, dest, (Vector2){0,0}, 0.0f, WHITE);
}

void unloadPipe(Pipe& pipe) {

}
