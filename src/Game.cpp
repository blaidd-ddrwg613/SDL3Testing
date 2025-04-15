#include "Game.h"

Game::Game(): mWindow(nullptr), mRenderer(nullptr), mIsRunning(true), mTicksCount(0) {}

bool Game::Init()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("ERROR::FAILED TO INIT SDL %s ", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("SDL Window", 1080, 720, 0);
    if (mWindow == NULL)
    {
        SDL_Log("ERROR::FAILED TO CREATE SDL WINDOW %s ", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, NULL);
    if (mRenderer == NULL)
    {
        SDL_Log("ERROR::FAILED TO CREATE SDL RENDERER %s ", SDL_GetError());
        return false;
    }

    return true;
}

void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_EVENT_QUIT:
                mIsRunning = false;
        }
    }

    const auto* keyboardState = reinterpret_cast<const Uint8 *>(SDL_GetKeyboardState(NULL));
    if (keyboardState[SDL_SCANCODE_ESCAPE])
    {
        mIsRunning = false;
    }
}

void Game::UpdateGame() {
    // Frame Limiting each frame will last 16ms
    while (!SDL_GetTicks() >= SDL_GetTicks() + 16);

    // Delta Time in seconds
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

    // Clamp maximum Delta time
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }
    // Update Tick count for next Frame
    mTicksCount = SDL_GetTicks();
}

void Game::GenerateOutput()
{
    SDL_SetRenderDrawColor(mRenderer, 150, 50, 175, 255);
    SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);
}
void Game::Shutdown()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}