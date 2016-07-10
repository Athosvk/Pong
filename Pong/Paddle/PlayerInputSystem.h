#pragma once
#include <Artifact/Core/System.h>

class PlayerInputSystem : public Artifact::System
{
public:
    PlayerInputSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

    virtual void registerListeners() override;
private:
    void handleInput();
};