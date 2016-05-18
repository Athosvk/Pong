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
			/// <summary>The relative position</summary>
			glm::vec2 RelativePosition = { 0.0f, 0.0f };
			/// <summary> The direction the particle is traveling in </summary>
			glm::vec2 Direction = { 1.0f, 0.0f };
			/// <summary> The life time </summary>
			float LifeTime = 0.0f;
		};
	private:
		/// <summary>The maximum amount of particles the emitter can use</summary>
		static constexpr unsigned s_MaxParticleCount = 100;
		/// <summary>The index of the first inactive particle</summary>
		size_t m_FirstInactive = 0;
	public:
		/// <summary> The spawn rate of the particles per second </summary>
		float SpawnRate;
		/// <summary> The maximum time in seconds before a particle dies </summary>
		float MaxLifeTime = 10.0f;		
		/// <summary> The speed of the particles when they are spawned </summary>
		float StartSpeed = 1.0f;		
		/// <summary>The speed of the particles when they are nearing the end of lifetime</summary>
		float EndSpeed = 1.0f;
		/// <summary> The color of the particles when they are spawned </summary>
		Color StartColor = Color::White;
		/// <summary> The color of the particles when they are at the end of lifetime </summary>
		Color EndColor = Color(1.0f, 1.0f, 1.0f, 0.0f);
		/// <summary>The time the simluation has been running for this particle emitter </summary>
		float SimulationTime;
		/// <summary>The particles</summary>
		std::array<Particle, s_MaxParticleCount> Particles;		
		/// <summary>The texture</summary>
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
		void update(double a_DeltaTime);

		/// <summary>Gets the index of the first inactive particles in the array</summary>
		/// <returns>The index of the first inactive particle</returns>
		size_t getFirstInactiveIndex() const;
	private:
		/// <summary>Deactivates the particle at given index</summary>
		/// <param name="a_Index">The index of the particle to deactivate</param>
		void deactivate(size_t a_Index);
	};
}