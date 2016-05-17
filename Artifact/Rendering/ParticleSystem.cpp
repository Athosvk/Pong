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
		m_MessagingSystem.registerListener<FixedUpdateMessage>([this](const Message* a_Message)
		{

		});
	}

	void ParticleSystem::render()
	{
	}

	void ParticleSystem::integrateAttributes() const
	{
	}
}
