#include <Artifact/Core/World.h>
#include <Artifact/Transform.h>

#include "MovementSystem.h"
#include "MovementComponent.h"

MovementSystem::MovementSystem(Artifact::EntitySystem& a_EntitySystem, 
    Artifact::MessagingSystem& a_MessagingSystem)
    : System(a_EntitySystem, a_MessagingSystem)
{
}

void MovementSystem::registerListeners()
{
    m_MessagingSystem.registerListener<Artifact::FixedUpdateMessage>([this](const Artifact::Message*)
    {
        updatePosition();
    });
}

void MovementSystem::updatePosition()
{
    for(auto movementComponent : m_EntitySystem.getComponentsOfType<MovementComponent>())
    {
        if(movementComponent->Direction != MovementComponent::EDirection::None)
        {
            auto transform = movementComponent->getComponent<Artifact::Transform>();
            transform->setPosition(transform->getPosition() + glm::vec2(static_cast<float>(movementComponent->Direction) *
                movementComponent->Speed));
        }
    }
}
