#include <Artifact/Physics/CollisionMessages.h>
#include <Artifact/Physics/BoxCollider2D.h>
#include <Artifact/Physics/RigidBody2D.h>
#include <Artifact/Core/EntitySystem.h>
#include <Artifact/Rendering/ParticleEmitter.h>
#include <Artifact/MathHelper.h>
#include <Artifact/Transform.h>
#include <Artifact/Rendering/SpriteRenderer.h>

#include "ReflectSystem.h"
#include "TagComponent.h"
#include "ReflectComponent.h"

ReflectSystem::ReflectSystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem)
	: System(a_EntitySystem, a_MessagingSystem)
{
}

void ReflectSystem::registerListeners()
{
	m_MessagingSystem.registerListener<Artifact::ComponentAddedMessage<ReflectComponent>>([this](const Artifact::Message* a_Message)
	{
		onReflectComponentAdded(static_cast<const Artifact::ComponentAddedMessage<ReflectComponent>*>(a_Message)->
			getAddedComponent());
	});
}

void ReflectSystem::reflect(Artifact::ComponentHandle<ReflectComponent> a_Reflecter, 
	Artifact::ComponentHandle<Artifact::BoxCollider2D> a_Ball)
{
	auto reflecterTransform = a_Reflecter->getComponent<Artifact::Transform>();
	auto reflecterNormal = Artifact::MathHelper::rotate(a_Reflecter->Normal,
		reflecterTransform->getRotation(), glm::vec2(0.0f));
	auto rigidBody = a_Ball->getComponent<Artifact::RigidBody2D>();
	auto velocity = rigidBody->getVelocity();
	float speed = static_cast<float>(glm::length(velocity)) * a_Reflecter->SpeedCoefficient;
	velocity = glm::normalize(velocity) * -1.0f;
	auto angle = Artifact::MathHelper::getSignedAngle(velocity, reflecterNormal);
	rigidBody->setVelocity(Artifact::MathHelper::rotate(velocity, angle * 2, glm::vec2(0.0f))
		* speed);
	a_Reflecter->getComponent<Artifact::ParticleEmitter>()->spawn(400);
	if(!(a_Reflecter->ReflectColor == Artifact::Color::White))
	{
		a_Ball->getComponent<Artifact::SpriteRenderer>()->Color = a_Reflecter->ReflectColor;
	}
}

void ReflectSystem::onReflectComponentAdded(Artifact::ComponentHandle<ReflectComponent> a_ReflectComponent)
{
	m_MessagingSystem.registerListener<Artifact::TriggerEnter2DMessage>([this, a_ReflectComponent]
		(const Artifact::Message* a_Message)
	{
		const Artifact::TriggerEnter2DMessage* message = static_cast<const Artifact::TriggerEnter2DMessage*>(a_Message);
		Artifact::ComponentHandle<TagComponent> tag = message->getOther()->getComponent<TagComponent>();
		if(tag != nullptr && tag->Tag == "Ball")
		{
			auto reflecter = message->getCollider()->getComponent<ReflectComponent>();
			if(!(tag->getComponent<Artifact::SpriteRenderer>()->Color == reflecter->ReflectColor)
				|| tag->getComponent<Artifact::SpriteRenderer>()->Color == Artifact::Color::White)
			{
				reflect(reflecter, message->getOther());
			}
		}
	}, a_ReflectComponent->getGameObject());
}
