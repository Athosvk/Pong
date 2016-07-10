#pragma once
#include <Artifact/Core/GameObject.h>

class Ball : public Artifact::GameObject
{
public:
    Ball(unsigned a_ID, Artifact::EntitySystem& a_EntitySystem);
};

