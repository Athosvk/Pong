#pragma once
#include <Artifact/Core/System.h>

class MovementSystem : public Artifact::System
{
public:
    MovementSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

    virtual void registerListeners();
private:
    void updatePositions();
};
