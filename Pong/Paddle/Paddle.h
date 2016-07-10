#pragma once
#include <Artifact/Core/GameObject.h>
#include <Artifact/Rendering/SpriteRenderer.h>

class Paddle : public Artifact::GameObject
{
private:
    Artifact::ComponentHandle<Artifact::SpriteRenderer> m_SpriteRenderer;
public:
    Paddle(unsigned a_ID, Artifact::EntitySystem& a_EntitySystem);

    void setColor(Artifact::Color a_Color);
};

