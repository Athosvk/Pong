#pragma once
#include <Artifact/Core/Component.h>
#include <Artifact/Input/Keycode.h>

class PlayerInputComponent : public Artifact::Component
{
public:
    Artifact::KeyCode MoveLeftKey = Artifact::KeyCode::Left;
    Artifact::KeyCode MoveRightKey = Artifact::KeyCode::Right;

public:
    PlayerInputComponent(Artifact::GameObject a_Entity);
};

