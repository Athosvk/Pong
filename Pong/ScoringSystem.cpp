#include <Artifact/Core/MessagingSystem.h>
#include <Artifact/Physics/CollisionMessages.h>
#include <Artifact/Physics/BoxCollider2D.h>
#include <Artifact/Rendering/SpriteRenderer.h>
#include <Artifact/Core/EntitySystem.h>
#include <Artifact/Transform.h>
#include <Artifact/Physics/RigidBody2D.h>

#include "ScoringSystem.h"
#include "TagComponent.h"
#include "ScoreComponent.h"
#include "BoundsComponent.h"

ScoringSystem::ScoringSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem)
	: System(a_EntitySystem, a_MessagingSystem)
{
}

void ScoringSystem::registerListeners()
{
	m_MessagingSystem.registerListener<Artifact::ComponentAddedMessage<BoundsComponent>>([this](const Artifact::Message* a_Message)
	{
		registerColliderListener(static_cast<const Artifact::ComponentAddedMessage<BoundsComponent>*>(a_Message)->getAddedComponent());
	});
}

void ScoringSystem::score(Artifact::Color a_ScoredColor)
{
	for(auto scoreComponent : m_EntitySystem.getComponentsOfType<ScoreComponent>())
	{
		if(scoreComponent->TeamColor == a_ScoredColor)
		{
			scoreComponent->CurrentScore += 1;
		}
	}
}

void ScoringSystem::registerColliderListener(Artifact::ComponentHandle<BoundsComponent> a_Collider)
{
	m_MessagingSystem.registerListener<Artifact::TriggerEnter2DMessage>([this](const Artifact::Message* a_Message)
	{
		auto tag = static_cast<const Artifact::TriggerEnter2DMessage*>(a_Message)->getOther()->getComponent<TagComponent>();
		if(tag->Tag == "Ball")
		{
			score(tag->getComponent<Artifact::SpriteRenderer>()->Color);
			tag->getComponent<Artifact::Transform>()->setPosition(glm::vec2(0.0f, 0.0f));
			tag->getComponent<Artifact::RigidBody2D>()->setVelocity(glm::vec2(0.f, -1.f));
			tag->getComponent<Artifact::SpriteRenderer>()->Color = Artifact::Color::White;
		}
	}, a_Collider->getGameObject());
}
