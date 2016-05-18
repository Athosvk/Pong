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
			auto gameTIme = static_cast<const UpdateMessage*>(a_Message)->getGameTime();
			updateParticleSimulations(static_cast<const UpdateMessage*>(a_Message)->getGameTime().getDeltaTime());
		});
	}

	void ParticleSystem::render()
	{
		m_SpriteBatch.begin(m_EntitySystem.getComponentsOfType<Camera2D>()[0]->getViewProjection());
		for(auto particleEmitter : m_EntitySystem.getComponentsOfType<ParticleEmitter>())
		{
			auto position = particleEmitter->getComponent<Transform>()->getPosition();
			for(size_t i = 0; i < particleEmitter->getFirstInactiveIndex(); ++i)
			{
				auto& particle = particleEmitter->Particles[i];
				float relativeLifeTime = particle.LifeTime / particleEmitter->MaxLifeTime;
				float size = lerp(particleEmitter->StartSize, particleEmitter->EndSize, relativeLifeTime);
				auto destinationRectangle = Artifact::Rectangle(position + particle.RelativePosition - glm::vec2(size / 2, size / 2), size, size);
				m_SpriteBatch.draw(particleEmitter->Texture, destinationRectangle, 
					lerp(particleEmitter->StartColor, particleEmitter->EndColor, relativeLifeTime));
			}
		}
		m_SpriteBatch.end();
	}

	void ParticleSystem::updateParticleSimulations(double a_DeltaTime) const
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
			particle.RelativePosition += particle.Direction * lerp(a_ParticleEmitter->StartSpeed, 
				a_ParticleEmitter->EndSpeed, relativeLifeTime);
		}
	}
}
