#pragma once
#include <raylib.h>
#include "constants.h"

struct Bird {
    Texture2D b_tex;
    float widthTex;
    float heightTex;
    Vector2 position;
    float gravityForce;
    float jumpForce;
    float velocityY;
};

void InitBird(Bird& bird);
void GravityBird(Bird& bird, float dt);
void UpdateBird(Bird& bird, float dt);
void DrawBird(const Bird& bird);
void UnloadBird(Bird& bird);
