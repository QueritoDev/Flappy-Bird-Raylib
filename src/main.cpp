#include <raylib.h>
#include "../include/bird.h"
#include "../include/constants.h"
#include "../include/pipe.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sys/types.h>
using namespace std;

int main() {
    cout << "Starting game" << endl;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Flappy Bird");
    SetTargetFPS(60);



    RenderTexture2D target = LoadRenderTexture(VIRTUAL_WIDTH, VIRTUAL_HEIGHT);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

    Rectangle sourceRec = { 0.0f, 0.0f, (float)VIRTUAL_WIDTH, -(float)VIRTUAL_HEIGHT };
    Rectangle destRec = { 0.0f, 0.0f, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT };

    Image background = LoadImage("../assets/images/background.png");
    Texture background_tex = LoadTextureFromImage(background);
    float backgroundScroll = 0;
    const float BACKGROUND_SCROLL_SPEED = 30;
    const float BACKGROUND_LOOPING_POINT = 413;
    UnloadImage(background);

    Image ground = LoadImage("../assets/images/ground.png");
    Texture ground_tex = LoadTextureFromImage(ground);
    float groundScroll = 0;
    float GROUND_SCROLL_SPEED = 60;
    UnloadImage(ground);

    Bird bird;
    initBird(bird);
    vector<Pipe> pipes;
    Texture2D pipe_tex = LoadTexture("../assets/images/pipe.png");
    float spawnTimer = 0;

    if (background_tex.id == 0) {
        TraceLog(LOG_ERROR, "ERRO: A imagem background.png nao foi carregada! Verifique o caminho.");
    }

    if (ground_tex.id == 0) {
        TraceLog(LOG_ERROR, "ERRO: A imagem ground.png nao foi carregada! Verifique o caminho.");
    }

    if (bird.b_tex.id == 0) {
        TraceLog(LOG_ERROR, "ERRO: A imagem bird.png nao foi carregada! Verifique o caminho.");
    }

    srand(time(nullptr));

    while(!WindowShouldClose()){
        float deltaTime = GetFrameTime();
        groundScroll = groundScroll + GROUND_SCROLL_SPEED * deltaTime;
        backgroundScroll = backgroundScroll + BACKGROUND_SCROLL_SPEED * deltaTime;

        if(groundScroll>=400) {
            groundScroll = 0;
        }

        if(backgroundScroll>=BACKGROUND_LOOPING_POINT) {
            backgroundScroll = 0;
        }

        updateBird(bird, deltaTime);
        spawnTimer += deltaTime;

        if(spawnTimer >= 2.0f) {
            Pipe newPipe;
            initPipe(newPipe, pipe_tex);
            pipes.push_back(newPipe);
            spawnTimer = 0.0f;
        }

        for (auto it = pipes.begin(); it != pipes.end();) {
            updatePipe(*it, deltaTime);

            if(it->position.x < -it->width) {
                it = pipes.erase(it);
            }else {
                ++it;
            }
        }

        BeginTextureMode(target);
            ClearBackground(RAYWHITE);
            DrawTexture(background_tex, -backgroundScroll, 0, WHITE);

            for (const Pipe& pipe : pipes) {
                drawPipe(pipe);
            }

            DrawTexture(ground_tex, -groundScroll, VIRTUAL_HEIGHT-16, WHITE);
            drawBird(bird);
        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(target.texture, sourceRec, destRec, (Vector2){0,0}, 0.0f, WHITE);
        EndDrawing();
    }
    for (auto& pipe : pipes) {
        unloadPipe(pipe);
    }
    UnloadRenderTexture(target);
    unloadBird(bird);
    CloseWindow();
    return 0;
}
