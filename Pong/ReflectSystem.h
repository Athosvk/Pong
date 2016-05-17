#pragma once
#include <Artifact/Core/System.h>
#include <Artifact/Core/ComponentHandle.h>
#include <Artifact/Physics/RigidBody2D.h>

#include "ReflectComponent.h"

class ReflectSystem : public Artifact::System
{
public:
	ReflectSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

	virtual void registerListeners() override;
private:
	void reflect(Artifact::ComponentHandle<Artifact::RigidBody2D> a_RigidBody);
	void onReflectComponentAdded(Artifact::ComponentHandle<ReflectComponent> a_ReflectComponent);
};