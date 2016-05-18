#include "ParticleSystem.h"
#include "RenderMessage.h"
#include "../Core/World.h"

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
		m_SpriteBatch.begin(m_EntitySystem.getComponentsOfType<Camera2D>()[0]->getComponent<Transform>()->getMatrix());
		for(auto particleEmitter : m_EntitySystem.getComponentsOfType<ParticleEmitter>())
		{
			for(size_t i = 0; i < particleEmitter->getFirstInactiveIndex(); i++)
			{
				auto& particle = particleEmitter->Particles[i];
				auto position = particleEmitter->getComponent<Transform>()->getPosition();
				m_SpriteBatch.draw(particleEmitter->Texture, position + particle.RelativePosition,
					lerp());
			}
		}
	}

	void ParticleSystem::updateParticleSimulations(float a_DeltaTime) const
	{
		for(auto particleEmitter : m_EntitySystem.getComponentsOfType<ParticleEmitter>())
		{
			particleEmitter->update(a_DeltaTime);
			integrateAttributes(particleEmitter);
		}
	}

	void ParticleSystem::integrateAttributes(ComponentHandle<ParticleEmitter> a_ParticleEmitter) const
	{
		for(size_t i = 0; i < a_ParticleEmitter->getFirstInactiveIndex(); ++i)
		{
			auto& particle = a_ParticleEmitter->Particles[i];
			float relativeLifeTime = particle.LifeTime / a_ParticleEmitter->MaxLifeTime;
			particle.RelativePosition += particle.Direction * lerp(a_ParticleEmitter->StartSpeed, a_ParticleEmitter->EndSpeed, relativeLifeTime);
		}
	}

	float ParticleSystem::lerp(Color a_Value1, Color a_Value2, Color a_T) const
	{
		return 
	}
}
