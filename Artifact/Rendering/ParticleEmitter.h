#pragma once
#include "../Core/Component.h"
#include "../Core/GameObject.h"

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

	public:		
		/// <summary>
		/// Initializes a new instance of the <see cref="ParticleEmmitter"/> class.
		/// </summary>
		/// <param name="a_GameObject">The GameObject this component belongs to </param>
		ParticleEmitter(GameObject a_GameObject);
	};
}