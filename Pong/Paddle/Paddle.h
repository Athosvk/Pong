#pragma once
#include <Artifact/Core/GameObject.h>

namespace Artifact
{
    class SpriteRenderer;
    struct Color;
}

class Paddle : public Artifact::GameObject
{
private:
    Artifact::SpriteRenderer* m_SpriteRenderer;
public:
    Paddle(unsigned a_ID, Artifact::EntitySystem& a_EntitySystem);

    void setColor(Artifact::Color a_Color);
};

