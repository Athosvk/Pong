#include "ParticleSystem.h"
#include "RenderMessage.h"
#include "../Core/World.h"
#include "ParticleEmitter.h"

namespace Artifact
{
	ParticleSystem::ParticleSystem(EntitySystem& a_EntitySystem, MessagingSystem& a_MessagingSystem)
		: System(a_EntitySystem, a_MessagingSystem)
	{
	}

	void ParticleSystem::registerListeners()
	{
		m_MessagingSystem.registerListener<RenderMessage>([this](const Message* a_Message)
		{
			render();
		});
		m_MessagingSystem.registerListener<UpdateMessage>([this](const Message* a_Message)
		{
			updateParticleSimulations(static_cast<const UpdateMessage*>(a_Message)->getGameTime().getDeltaTime());
		});
	}

	void ParticleSystem::render()
	{
	}

	void ParticleSystem::updateParticleSimulations(float a_DeltaTime) const
	{
		for(auto particleEmitter : m_EntitySystem.getComponentsOfType<ParticleEmitter>())
		{
			integrateAttributes(particleEmitter);
			
		}
	}

	void ParticleSystem::integrateAttributes(ComponentHandle<ParticleEmitter> a_ParticleEmitter) const
	{
		for(size_t i = 0; i < a_ParticleEmitter->getFirstInactiveIndex(); i++)
		{

		}
	}
}
