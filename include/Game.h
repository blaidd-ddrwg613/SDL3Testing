#pragma once

#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"

class Game
{
public:
    Game();
    bool Init();
    void RunLoop();
    void Shutdown();

    Uint32 mTicksCount;

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;

    bool mIsRunning;
};