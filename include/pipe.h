#pragma once
#include <raylib.h>

struct Pipe {
    Texture2D texture;
    float pipeScroll;
    float widthTex;
    float heightTex;
    Vector2 position;
};

void InitPipe(Pipe& pipe);
void DrawPipe(const Pipe& pipe);
void UpdatePipe(Pipe& pipe, float dt);
void UnloadPipe(Pipe& pipe);
