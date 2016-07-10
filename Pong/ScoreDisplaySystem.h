#pragma once
#include <Artifact/Core/System.h>

class ScoreDisplaySystem : public Artifact::System
{
public:
	ScoreDisplaySystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem);

	virtual void registerListeners() override;
private:
	void drawScore();
};

