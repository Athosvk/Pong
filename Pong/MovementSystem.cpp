#include <Artifact/Core/World.h>
#include <Artifact/Transform.h>
#include <Artifact/MathHelper.h>

#include "MovementSystem.h"
#include "MovementComponent.h"
#include "MovementCircleComponent.h"

MovementSystem::MovementSystem(Artifact::EntitySystem& a_EntitySystem, 
    Artifact::MessagingSystem& a_MessagingSystem)
    : System(a_EntitySystem, a_MessagingSystem)
{
}

void MovementSystem::registerListeners()
{
    m_MessagingSystem.registerListener<Artifact::AwakeMessage>([this](const Artifact::Message*)
    {
        setInitialPositions();
    });
    m_MessagingSystem.registerListener<Artifact::FixedUpdateMessage>([this](const Artifact::Message*)
    {
        updatePositions();
    });
}

void MovementSystem::setInitialPositions() const
{
    auto movementCircle = getMovementCircle();
    for(auto movementComponent : m_EntitySystem.getComponentsOfType<MovementComponent>())
    {
        auto transform = movementComponent->getComponent<Artifact::Transform>();
        transform->setPosition(movementCircle->getComponent<Artifact::Transform>()->getPosition()
            + glm::vec2(0.0f, 1.0f) * movementCircle->Radius);
    }
}

void MovementSystem::updatePositions() const
{
    auto movementCircle = getMovementCircle();

    for(auto movementComponent : m_EntitySystem.getComponentsOfType<MovementComponent>())
    {
        if(movementComponent->Direction != MovementComponent::EDirection::None)
        {
            updatePosition(movementComponent, movementCircle);
        }
    }
}

void MovementSystem::updatePosition(MovementComponent* a_Movement, MovementCircleComponent* a_Circle) const
{
    auto transform = a_Movement->getComponent<Artifact::Transform>();
    auto angularDisplacement = static_cast<float>(a_Movement->Direction) * a_Movement->Speed;
    auto position = Artifact::MathHelper::rotate(transform->getPosition(), angularDisplacement,
        a_Circle->getComponent<Artifact::Transform>()->getPosition());
    transform->setPosition(position);
}

MovementCircleComponent* MovementSystem::getMovementCircle() const
{
    return m_EntitySystem.getComponentsOfType<MovementCircleComponent>()[0];
}
