#include <Artifact/Core/EntitySystem.h>
#include <Artifact/Rendering/TextComponent.h>
#include <Artifact/Rendering/RenderMessage.h>
#include <Artifact/Rendering/SpriteRenderer.h>
#include <Artifact/Rendering/ParticleEmitter.h>
#include <Artifact/MathHelper.h>

#include "DebugPanelSystem.h"
#include "DebugPanelComponent.h"

DebugPanelSystem::DebugPanelSystem(Artifact::EntitySystem& a_EntitySystem,
	Artifact::MessagingSystem& a_MessagingSystem)
	: System(a_EntitySystem, a_MessagingSystem)
{
}

void DebugPanelSystem::registerListeners()
{
	m_MessagingSystem.registerListener<Artifact::RenderMessage>([this](const Artifact::Message*)
	{
		auto debugPanel = getDebugPanel();
		if(debugPanel->isEnabled())
		{
			drawPanel(debugPanel);
		}
	});
}

void DebugPanelSystem::drawPanel(Artifact::ComponentHandle<DebugPanelComponent> a_DebugPanel)
{
	std::string text = "\nParticle emitters:\n";
	int emitterIndex = 0;
	for(auto particleEmitter : m_EntitySystem.getComponentsOfType<Artifact::ParticleEmitter>())
	{
		emitterIndex++;
		if(particleEmitter->isEnabled())
		{
			text += "\nParticle emitter " + std::to_string(emitterIndex);
			text += "\nStart speed: " + 
				std::to_string(Artifact::MathHelper::round(particleEmitter->StartSpeed, 1));
			text += "\nEnd speed: " + 
				std::to_string(Artifact::MathHelper::round(particleEmitter->EndSpeed, 1));
			text += "\nStart size: " + 
				std::to_string(Artifact::MathHelper::round(particleEmitter->StartSize, 1));
			text += "\nEnd size: " + 
				std::to_string(Artifact::MathHelper::round(particleEmitter->EndSize, 1));
			text += "\nEmission cone: " + 
				std::to_string(Artifact::MathHelper::round(particleEmitter->MinAngle))
				+ " - " + std::to_string(Artifact::MathHelper::round(particleEmitter->MaxAngle));
			text += "\nSpawn interval: " + 
				std::to_string(Artifact::MathHelper::round(particleEmitter->SpawnInterval)) + " s";
			text += "\nActive particles: " + 
				std::to_string(static_cast<int>(particleEmitter->getFirstInactiveIndex()));
			text += "\n";
		}
	}
	a_DebugPanel->getComponent<Artifact::SpriteRenderer>()->Height = emitterIndex * 1.3f;
	a_DebugPanel->getText()->Text = text;
}

Artifact::ComponentHandle<DebugPanelComponent> DebugPanelSystem::getDebugPanel() const
{
	return m_EntitySystem.getComponentsOfType<DebugPanelComponent>()[0];
}
