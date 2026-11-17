#pragma once
#include <raylib.h>


struct Pipe {
    Texture2D tex;
    float pipeScroll;
    float width;
    Vector2 position;
};

void initPipe(Pipe& pipe);
void updatePipe(Pipe& pipe);
void drawPipe(const Pipe& pipe);
void unloadPipe(Pipe& pipe);

