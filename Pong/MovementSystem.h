#pragma once
#include <Artifact/Core/System.h>
#include <Artifact/Core/ComponentHandle.h>

#include "MovementCircleComponent.h"
#include "MovementComponent.h"

class MovementSystem : public Artifact::System
{
public:
    MovementSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

    virtual void registerListeners();
private:
    void setInitialPositions() const;
    void updatePositions() const;
    void updatePosition(Artifact::ComponentHandle<MovementComponent> a_Movement, 
		Artifact::ComponentHandle<MovementCircleComponent> a_Circle) const;

    Artifact::ComponentHandle<MovementCircleComponent> getMovementCircle() const;
};
