#pragma once
#include <Artifact/Core/Component.h>
#include <glm/glm.hpp>

class ReflectComponent : public Artifact::Component
{
public:
	glm::vec2 Normal = glm::vec2(0.0f, -1.0f);
	float SpeedCoefficient = 1.1f;
public:
	ReflectComponent(Artifact::GameObject a_Entity);
};
