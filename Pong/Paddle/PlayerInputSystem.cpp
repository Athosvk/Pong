#include <Artifact/Input/InputSystem.h>
#include <Artifact/Core/EntitySystem.h>

#include "PlayerInputSystem.h"
#include "PlayerInputComponent.h"
#include "../MovementComponent.h"

PlayerInputSystem::PlayerInputSystem(Artifact::EntitySystem& a_EntitySystem, 
    Artifact::MessagingSystem& a_MessagingSystem)
    : System(a_EntitySystem, a_MessagingSystem)
{
}

void PlayerInputSystem::registerListeners()
{
    m_MessagingSystem.registerListener<Artifact::HandleInputMessage>([this](const Artifact::Message*)
    {
        handleInput();
    });
}

void PlayerInputSystem::handleInput()
{
    for(auto inputComponent : m_EntitySystem.getComponentsOfType<PlayerInputComponent>())
    {
        auto movementComponent = inputComponent->getComponent<MovementComponent>();
        if(Artifact::Keyboard::isDown(inputComponent->MoveLeftKey))
        {
            movementComponent->Direction = MovementComponent::EDirection::Left;
        }
        else if(Artifact::Keyboard::isDown(inputComponent->MoveRightKey))
        {
            movementComponent->Direction = MovementComponent::EDirection::Right;
        }
        else
        {
            movementComponent->Direction = MovementComponent::EDirection::None;
        }
    }
}
