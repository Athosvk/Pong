#pragma once
#include <Artifact/Core/Component.h>

class MovementComponent : public Artifact::Component
{
public:
    float Speed = 0.1f;
    enum class EDirection
    {
        Left = -1,
        None = 0,
        Right = 1
    } Direction = EDirection::None;

public:
    MovementComponent(Artifact::GameObject a_Entity);
};

