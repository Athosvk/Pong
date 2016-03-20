#pragma once
#include <Artifact/Core/System.h>

class MovementComponent;
class MovementCircleComponent;

class MovementSystem : public Artifact::System
{
public:
    MovementSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

    virtual void registerListeners();
private:
    void setInitialPositions() const;
    void updatePositions() const;
    void updatePosition(MovementComponent* a_Movement, MovementCircleComponent* a_Circle) const;

    MovementCircleComponent* getMovementCircle() const;
};
