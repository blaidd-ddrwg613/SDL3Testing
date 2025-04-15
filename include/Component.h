#pragma once

#include "Actor.h"

class Component
{
public:
    // The lower the UpdateOrder the earlier the component will updated
    Component(class Actor* owner, int UpdateOrder = 100);
    virtual ~Component();
    virtual void Update(float deltaTime);
    int GetUpdateOrder() const {return mUpdateOrder;}

protected:
    // Owning Actor
    Actor* mOwner;
    int mUpdateOrder;
};
