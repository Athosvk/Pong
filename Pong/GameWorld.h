#pragma once
#include <Artifact/Core/World.h>

class GameWorld : public Artifact::World
{
public:
    GameWorld(Artifact::GameTime& a_GameTime, Artifact::Game* a_CurrentGame);
};

