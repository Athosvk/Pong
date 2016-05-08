#pragma once
#include <Artifact/Core/System.h>

namespace Artifact
{
	class RigidBody2D;
}
class ReflectComponent;

class ReflectSystem : public Artifact::System
{
public:
	ReflectSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

	virtual void registerListeners() override;
private:
	void reflect(Artifact::RigidBody2D* a_RigidBody);
	void onReflectComponentAdded(ReflectComponent* a_ReflectComponent);
};