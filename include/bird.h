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

void initBird(Bird& bird);
void gravityBird(Bird& bird, float dt);
void updateBird(Bird& bird, float dt);
void drawBird(const Bird& bird);
void unloadBird(Bird& bird);
