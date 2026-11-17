#include "../include/bird.h"
#include <raylib.h>
#include "raymath.h"

void initBird(Bird& bird) {
    bird.b_tex = LoadTexture("../assets/images/bird.png");
    bird.widthTex = bird.b_tex.width;
    bird.heightTex = bird.b_tex.height;

    bird.position = {VIRTUAL_WIDTH / 2 - bird.widthTex / 2, VIRTUAL_HEIGHT / 2 - bird.heightTex/ 2};

    bird.velocityY = 0.0f;
    bird.gravityForce = 700.0f;
    bird.jumpForce = 450.0f;
}

void gravityBird(Bird& bird, float dt) {
    bird.velocityY += bird.gravityForce * dt;

    bird.velocityY = Clamp(bird.velocityY, -150.0f, 900.0f);

    bird.position.y += bird.velocityY * dt;
}

void UpdateBird(Bird& bird, float dt) {
    if(IsKeyPressed(KEY_UP)) {
        bird.velocityY -= bird.jumpForce;
    }

    gravityBird(bird, dt);

}



void drawBird(const Bird& bird) {
    DrawTexture(bird.b_tex, bird.position.x, bird.position.y, WHITE);
}

void unloadBird(Bird& bird) {
    UnloadTexture(bird.b_tex);
}
