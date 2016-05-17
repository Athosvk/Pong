#pragma once
#include <glm/glm.hpp>
#include <array>

#include "../Core/Component.h"
#include "../Core/GameObject.h"
#include "../Color.h"
#include "../GL/GLTexture.h"

namespace Artifact
{
	/// <summary> A particle emmitter, capable of emitting collections of particles </summary>
	/// <seealso cref="Component" />
	class ParticleEmitter : public Component
	{
	private:		
		/// <summary> A single particle instance for drawing </summary>
		struct Particle
		{
			/// <summary> The position relative  </summary>
			glm::vec2 RelativePosition = { 0.0f, 0.0f };
			/// <summary> The life time </summary>
			float LifeTime = 0.0f;
		};
	private:
		static constexpr unsigned s_MaxParticleCount = 100;
		size_t m_FirstInactive = 0;
	public:
		/// <summary> The spawn rate of the particles per second </summary>
		float SpawnRate;
		/// <summary> The maximum time in seconds before a particle dies </summary>
		float MaxLifeTime = 1.0f;		
		/// <summary> The velocity of the particles when they are spawned </summary>
		glm::vec2 StartVelocity = { 0.0f, 0.0f };		
		/// <summary> The end velocity </summary>
		glm::vec2 EndVelocity = { 0.0f, 0.0f };
		/// <summary> The color of the particles when they are spawned </summary>
		Color StartColor = Color::White;
		/// <summary> The color of the particles when they are at the end of lifetime </summary>
		Color EndColor = Color(1.0f, 1.0f, 1.0f, 0.0f);
		/// <summary>The time the simluation has been running for this particle emitter </summary>
		float SimulationTime;
		/// <summary>The particles</summary>
		std::array<Particle, s_MaxParticleCount> Particles;
		GLTexture* Texture = nullptr;

	public:		
		/// <summary>
		/// Initializes a new instance of the <see cref="ParticleEmmitter"/> class.
		/// </summary>
		/// <param name="a_GameObject">The GameObject this component belongs to </param>
		ParticleEmitter(GameObject a_GameObject);
		
		/// <summary>Activates the specified amount of particles, restricted to the maximum amount of particles </summary>
		/// <param name="a_Count">The a_ count.</param>
		void spawn(unsigned a_Count);
		
		/// <summary>Updates simulation by the specified time</summary>
		/// <param name="a_DeltaTime">The a_ delta time.</param>
		void update(float a_DeltaTime);
	private:
		void deactivate(size_t a_Index);
	};
}