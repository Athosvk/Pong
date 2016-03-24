#include <Artifact/Physics/BoxCollider2D.h>
#include <Artifact/Physics/RigidBody2D.h>
#include <Artifact/Rendering/SpriteRenderer.h>
#include <Artifact/IO/ResourceManager.h>
#include <Artifact/Core/EntitySystem.h>

#include "Ball.h"
#include "TagComponent.h"

Ball::Ball(unsigned a_ID, Artifact::EntitySystem& a_EntitySystem)
    : GameObject(a_ID, a_EntitySystem)
{
    const auto Dimensions = glm::vec2(0.1f, 0.1f);

    auto tag = addComponent<TagComponent>();
    tag->Tag = "Ball";

    auto rigidBody = addComponent<Artifact::RigidBody2D>();
    rigidBody->setGravityScale(0.0f);
    rigidBody->setVelocity(glm::vec2(0.0f, -2.0f));

    auto collider = addComponent<Artifact::BoxCollider2D>();
    collider->enableTriggerState();
    collider->setDimensions(Dimensions);

    auto spriteRenderer = addComponent<Artifact::SpriteRenderer>();
    spriteRenderer->Width = Dimensions.x;
    spriteRenderer->Height = Dimensions.y;
    spriteRenderer->setTexture(Artifact::ResourceManager::getTexture("Assets/Textures/Paddle.png"));
}
