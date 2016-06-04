#include <Artifact/Rendering/TextComponent.h>
#include <Artifact/Core/EntitySystem.h>
#include <Artifact/IO/ResourceManager.h>

#include "ScoreDisplayComponent.h"

ScoreDisplayComponent::ScoreDisplayComponent(Artifact::GameObject a_GameObject)
	: Component(a_GameObject),
	Text(addComponent<Artifact::TextComponent>())
{
	Text->Text = std::to_string(0);
	Text->Font = Artifact::ResourceManager::getInstance().
		getFont("Assets/Fonts/Helvetica Bold.ttf");
	Text->Color = Artifact::Color::White;
	Text->Depth = 1;
	Text->Scaling = 0.35f;
}

void ScoreDisplayComponent::setScoreComponent(Artifact::ComponentHandle<ScoreComponent> a_ScoreComponent)
{
	m_Score = a_ScoreComponent;
	Text->Color = a_ScoreComponent->TeamColor;
}

Artifact::ComponentHandle<ScoreComponent> ScoreDisplayComponent::getScoreComponent() const
{
	return m_Score;
}
