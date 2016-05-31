#include <string>

#include <Artifact/Core/MessagingSystem.h>
#include <Artifact/Rendering/RenderMessage.h>
#include <Artifact/Core/EntitySystem.h>
#include <Artifact/Rendering/TextComponent.h>

#include "ScoreDisplaySystem.h"
#include "ScoreDisplayComponent.h"

ScoreDisplaySystem::ScoreDisplaySystem(Artifact::EntitySystem& a_EntitySystem, Artifact::MessagingSystem& a_MessagingSystem)
	: System(a_EntitySystem, a_MessagingSystem)
{
}

void ScoreDisplaySystem::registerListeners()
{
	m_MessagingSystem.registerListener<Artifact::RenderMessage>([this](const Artifact::Message* a_Message)
	{
		drawScore();
	});
}

void ScoreDisplaySystem::drawScore()
{
	for(auto scoreDisplay : m_EntitySystem.getComponentsOfType<ScoreDisplayComponent>())
	{
		scoreDisplay->Text->Text = 
			std::to_string(scoreDisplay->getScoreComponent()->CurrentScore);
	}
}
