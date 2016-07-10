#pragma once
#include <Artifact/Core/Component.h>

class MovementComponent : public Artifact::Component
{
public:
    float Speed = 0.5f;
    enum class EDirection
    {
        Left = -1,
        None = 0,
        Right = 1
    } Direction = EDirection::None;
	float Angle = 0.0f;

public:
    MovementComponent(Artifact::GameObject a_Entity);
};

