#include <Artifact/Core/EntitySystem.h>
#include <Artifact/Rendering/SpriteRenderer.h>
#include <Artifact/IO/ResourceManager.h>
#include <Artifact/Physics/BoxCollider2D.h>
#include <Artifact/Physics/RigidBody2D.h>

#include "Paddle.h"
#include "PlayerInputComponent.h"
#include "../MovementComponent.h"
#include "../TagComponent.h"

Paddle::Paddle(unsigned a_ID, Artifact::EntitySystem& a_EntitySystem)
    : GameObject(a_ID, a_EntitySystem)
{
    addComponent<PlayerInputComponent>();
    addComponent<MovementComponent>();

    m_SpriteRenderer = addComponent<Artifact::SpriteRenderer>();
    m_SpriteRenderer->setTexture(Artifact::ResourceManager::getTexture("Assets/Textures/Paddle.png"));
    m_SpriteRenderer->Width = 1.0f;
    m_SpriteRenderer->Height = 0.2f;

    auto collider = addComponent<Artifact::BoxCollider2D>();
    collider->setDimensions(glm::vec2(1.0f, 0.2f));
    collider->enableTriggerState();
    auto rigidBody = addComponent<Artifact::RigidBody2D>();
    rigidBody->setGravityScale(0.0f);

    auto tag = addComponent<TagComponent>();
    tag->Tag = "Paddle";
}

void Paddle::setColor(Artifact::Color a_Color)
{
    m_SpriteRenderer->Color = a_Color;
}
