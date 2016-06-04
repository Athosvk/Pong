#include <Artifact/Physics/BoxCollider2D.h>
#include <Artifact/Rendering/SpriteRenderer.h>
#include <Artifact/IO/ResourceManager.h>
#include <Artifact/Core/EntitySystem.h>

#include "Boundary.h"
#include "BoundsComponent.h"

Boundary::Boundary(unsigned a_ID, Artifact::EntitySystem& a_EntitySystem)
	: GameObject(a_ID, a_EntitySystem)
{
	addComponent<BoundsComponent>();
	auto boxCollider = addComponent<Artifact::BoxCollider2D>();
	boxCollider->setDimensions(glm::vec2(10.0f, 0.2f));
	boxCollider->enableTriggerState();
}