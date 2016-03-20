#pragma once
#include <Artifact/Core/Component.h>

class MovementCircleComponent : public Artifact::Component
{
public:
    float Radius = 1.0f;
public:
    MovementCircleComponent(Artifact::GameObject a_GameObject);
};

