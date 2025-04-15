#pragma once

#include <vector>

#include "Game.h"
#include "glm/vec2.hpp"
#include "Component.h"

class Actor
{
public:
    enum State
    {
        EActive,
        EPaused,
        EDead
    };

    Actor(class Game* game);
    virtual ~Actor();

    // Update Functions called from Game (Not Overridable)
    void Update(float deltaTime);
    // Updates all components Attached to the Actor (Not Overridable)
    void UpdateComponents(float deltaTime);
    // Ant Actor specific update code
    virtual void UpdateActor(float deltaTime);

    // Getters and Setters
    const glm::vec2 & GetPosition() const { return mPosition; }
    void SetPosition(const glm::vec2 pos) { mPosition = pos; }
    float GetScale() const { return mScale; }
    void SetScale(float scale) { mScale = scale; }
    float GetRotation() const { return mRotation; }
    void SetRotation(float rotation) { mRotation = rotation; }

    State GetState() const { return mState; }
    void SetState(State state) { mState = state; }

    class Game* GetGame() { return mGame; }

    // Add/Remove components
    void AddComponent(class Component* component);
    void RemoveComponent(class Component* component);

private:
    // Actors State
    State mState;
    // Transform
    glm::vec2 mPosition;
    float mScale;
    float mRotation;
    // Components
    std::vector<class Component*> mComponents;
    Game* mGame;
};