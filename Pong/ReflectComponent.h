#pragma once
#include <glm/glm.hpp>

#include <Artifact/Color.h>
#include <Artifact/Core/Component.h>

class ReflectComponent : public Artifact::Component
{
public:
	glm::vec2 Normal = glm::vec2(0.0f, -1.0f);
	float SpeedCoefficient = 1.1f;
	Artifact::Color ReflectColor = Artifact::Color::White;
public:
	ReflectComponent(Artifact::GameObject a_Entity);
};
