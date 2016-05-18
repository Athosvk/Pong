#include "ParticleEmitter.h"
#include "../MathHelper.h"

namespace Artifact
{
	ParticleEmitter::ParticleEmitter(GameObject a_GameObject)
		: Component(a_GameObject)
	{
	}

	void ParticleEmitter::spawn(unsigned a_Count)
	{
		auto newFirstInactive = static_cast<size_t>(MathHelper::min(s_MaxParticleCount, m_FirstInactive + a_Count));
		for(size_t i = m_FirstInactive; i < newFirstInactive; ++i)
		{
			Particles[i] = Particle();
		}
		m_FirstInactive = newFirstInactive;
	}

	void ParticleEmitter::update(float a_DeltaTime)
	{
		SimulationTime += a_DeltaTime;
		for(size_t i = 0; i < m_FirstInactive; ++i)
		{
			if(Particles[i].LifeTime >= MaxLifeTime)
			{
				deactivate(i);
			}
		}
	}

	size_t ParticleEmitter::getFirstInactiveIndex() const
	{
		return m_FirstInactive;
	}

	void ParticleEmitter::deactivate(size_t a_Index)
	{
		std::swap(Particles[a_Index], Particles[m_FirstInactive - 1]);
		m_FirstInactive--;
	}
}
