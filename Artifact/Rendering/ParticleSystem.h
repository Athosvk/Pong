#pragma once
#include "../Core/System.h"
#include "SpriteBatch.h"

namespace Artifact
{
	class ParticleSystem : public System
	{
	private:
		SpriteBatch m_SpriteBatch;
	public:
		ParticleSystem(EntitySystem& a_EntitySystem, MessagingSystem& a_MessagingSystem);

		virtual void registerListeners() override;
	private:
		void render();
		void fixedUpdate();
	};
}
