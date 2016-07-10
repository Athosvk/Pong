#pragma once
#include <Artifact/Core/Component.h>
#include <Artifact/Color.h>

class ScoreComponent : public Artifact::Component
{
public:
	Artifact::Color TeamColor;
	int CurrentScore = 0;

public:
	ScoreComponent(Artifact::GameObject a_GameObject);
};

