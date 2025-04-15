#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"

#include "Actor.h"

class Game
{
public:
    Game();
    bool Init();
    void RunLoop();
    void Shutdown();

    void AddActor(class Actor* actor);
    void RemoveActor(class Actor* actor);

    Uint32 mTicksCount;
    float deltaTime;

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();
    void LimitFrames(int durationMs);
    float GetDeltaTime();
    void ClampDeltaTime(float maxAmount);
    void UpdateActors();
    void UnloadData();

    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;

    bool mIsRunning;
    bool mUpdatingActors;

    std::unordered_map<std::string, SDL_Texture*> mTextures;

    std::vector<Actor*> mActiveActors;
    std::vector<Actor*> mPendingActors;
    std::vector<class SpriteComponent*> mSprites;
};