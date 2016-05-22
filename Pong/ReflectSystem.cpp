#include <Artifact/Physics/CollisionMessages.h>
#include <Artifact/Physics/BoxCollider2D.h>
#include <Artifact/Physics/RigidBody2D.h>
#include <Artifact/Core/EntitySystem.h>
#include <Artifact/Rendering/ParticleEmitter.h>

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

void ReflectSystem::reflect(Artifact::ComponentHandle<Artifact::RigidBody2D> a_RigidBody)
{
	a_RigidBody->setVelocity(a_RigidBody->getVelocity() * -1.05f);
}

void ReflectSystem::onReflectComponentAdded(Artifact::ComponentHandle<ReflectComponent> a_ReflectComponent)
{
	m_MessagingSystem.registerListener<Artifact::TriggerEnter2DMessage>([this](const Artifact::Message* a_Message)
	{
		const Artifact::TriggerEnter2DMessage* message = static_cast<const Artifact::TriggerEnter2DMessage*>(a_Message);
		Artifact::ComponentHandle<TagComponent> tag = message->getOther()->getComponent<TagComponent>();
		if(tag != nullptr && tag->Tag == "Ball")
		{
			reflect(tag->getComponent<Artifact::RigidBody2D>());
			message->getCollider()->getComponent<Artifact::ParticleEmitter>()->spawn(100);
		}
	}, a_ReflectComponent->getGameObject());
}
