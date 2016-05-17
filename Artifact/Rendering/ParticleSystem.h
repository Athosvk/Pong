#pragma once
#include "../Core/System.h"
#include "SpriteBatch.h"


namespace Artifact
{
	/// <summary> The system drawing the particles of each particle emmitter </summary>
	/// <seealso cref="System" />
	class ParticleSystem : public System
	{
	private:
		/// <summary>The SpriteBatch to draw the particles with</summary>
		SpriteBatch m_SpriteBatch;
	public:
		/// <summary>Initializes a new instance of the <see cref="ParticleSystem"/> class.</summary>
		/// <param name="a_EntitySystem">The entity system to operate on, so that it can fetch the needed components </param>
		/// <param name="a_MessagingSystem">The a_ messaging system.</param>
		ParticleSystem(EntitySystem& a_EntitySystem, MessagingSystem& a_MessagingSystem);

		/// <summary>Registers the listeners for the messages it will listen to </summary>
		virtual void registerListeners() override;
	private:
		/// <summary>Renders the particles of each particle emitters </summary>
		void render();
		
		/// <summary>Updates the particle simulations</summary>
		/// <param name="a_DeltaTime">The tiem since hte last update</param>
		void updateParticleSimulations(float a_DeltaTime) const;

		/// <summary>Integrates the attributes of each particle using their corresponding emitter </summary>
		void integrateAttributes(ComponentHandle<ParticleEmitter> a_ParticleEmitter) const;
		void update();
	};
}
