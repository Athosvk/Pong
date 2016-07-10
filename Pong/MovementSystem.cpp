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
    m_MessagingSystem.registerListener<Artifact::FixedUpdateMessage>([this](const Artifact::Message*)
    {
        updatePositions();
    });
}

void MovementSystem::updatePositions() const
{
    auto movementCircle = getMovementCircle();

    for(auto movementComponent : m_EntitySystem.getComponentsOfType<MovementComponent>())
    {
         updatePosition(movementComponent, movementCircle);
    }
}

void MovementSystem::updatePosition(Artifact::ComponentHandle<MovementComponent> a_Movement,
	Artifact::ComponentHandle<MovementCircleComponent> a_Circle) const
{
    auto transform = a_Movement->getComponent<Artifact::Transform>();
    auto angularDisplacement = static_cast<float>(a_Movement->Direction) * a_Movement->Speed + a_Movement->Angle;
	a_Movement->Angle = angularDisplacement;
    auto position = Artifact::MathHelper::rotate(glm::vec2(a_Circle->Radius, 0.0f), angularDisplacement,
        a_Circle->getComponent<Artifact::Transform>()->getPosition());
    transform->setPosition(position);
    transform->setRotation(angularDisplacement - 90.0f);
}

Artifact::ComponentHandle<MovementCircleComponent> MovementSystem::getMovementCircle() const
{
    return m_EntitySystem.getComponentsOfType<MovementCircleComponent>()[0];
}
