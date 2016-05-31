#pragma once
#include <Artifact/Core/System.h>
#include <Artifact/Color.h>

namespace Artifact
{
	class BoxCollider2D;
}

class BoundsComponent;

class ScoringSystem : public Artifact::System
{
public:
	ScoringSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

	virtual void registerListeners() override;
private:
	void score(Artifact::Color a_ScoredColor);
	void registerColliderListener(Artifact::ComponentHandle<BoundsComponent> a_Collider);
};

