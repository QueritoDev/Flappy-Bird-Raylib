#pragma once
#include <raylib.h>

const int MAX_PIPES = 4;
const float PIPE_SPACING = 150.0f;

struct Pipe {
    float pipeScroll;
    Vector2 position;
};

struct PipeManager {
    Texture2D texture;
    Pipe pipes[MAX_PIPES];
};

void InitPipes(PipeManager& manager);
void UpdatePipes(PipeManager& manager, float dt);
void DrawPipes(const PipeManager& manager);
void UnloadPipes(PipeManager& manager);
