#pragma once
#include <Artifact/Core/System.h>

namespace Artifact
{
	class ParticleEmitter;
}

class DebugPanelComponent;

class DebugPanelSystem : public Artifact::System
{
public:
	DebugPanelSystem(Artifact::EntitySystem& a_EntitySystem,
		Artifact::MessagingSystem& a_MessagingSystem);

	virtual void registerListeners() override;
private:
	void drawPanel(Artifact::ComponentHandle<DebugPanelComponent> a_DebugPanel);
	Artifact::ComponentHandle<DebugPanelComponent> getDebugPanel() const;
};

