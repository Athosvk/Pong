#include <Artifact/Core/EntitySystem.h>
#include <Artifact/Rendering/SpriteRenderer.h>
#include <Artifact/IO/ResourceManager.h>

#include "Paddle.h"
#include "PlayerInputComponent.h"
#include "../MovementComponent.h"

Paddle::Paddle(unsigned a_ID, Artifact::EntitySystem& a_EntitySystem)
    : GameObject(a_ID, a_EntitySystem)
{
    addComponent<PlayerInputComponent>();
    addComponent<MovementComponent>();

    m_SpriteRenderer = addComponent<Artifact::SpriteRenderer>();
    m_SpriteRenderer->setTexture(Artifact::ResourceManager::getTexture("Assets/Textures/Paddle.png"));
    m_SpriteRenderer->Width = 1.0f;
    m_SpriteRenderer->Height = 0.2f;
}

void Paddle::setColor(Artifact::Color a_Color)
{
    m_SpriteRenderer->Color = a_Color;
}
