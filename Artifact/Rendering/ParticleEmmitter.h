#pragma once
#include "../Core/Component.h"
#include "../Core/GameObject.h"

namespace Artifact
{
	class ParticleEmmitter : public Component
	{
	public:
		ParticleEmmitter(GameObject a_GameObject);
	};
}