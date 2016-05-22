#pragma once
#include <Artifact/Core/System.h>
#include <Artifact/Core/ComponentHandle.h>

namespace Artifact
{
	class BoxCollider2D;
}

class ReflectComponent;

class ReflectSystem : public Artifact::System
{
public:
	ReflectSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

	virtual void registerListeners() override;
private:
	void reflect(Artifact::ComponentHandle<ReflectComponent> a_Reflecter, 
		Artifact::ComponentHandle<Artifact::BoxCollider2D> a_Ball);
	void onReflectComponentAdded(Artifact::ComponentHandle<ReflectComponent> a_ReflectComponent);
};