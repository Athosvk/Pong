#include <Artifact/Rendering/SpriteFont.h>
#include <Artifact/Rendering/TextComponent.h>
#include <Artifact/Core/EntitySystem.h>
#include <Artifact/IO/ResourceManager.h>
#include <Artifact/Rendering/SpriteRenderer.h>

#include "DebugPanelComponent.h"

DebugPanelComponent::DebugPanelComponent(Artifact::GameObject a_GameObject)
	: Component(a_GameObject),
	m_Text(addComponent<Artifact::TextComponent>())
{
}

Artifact::ComponentHandle<Artifact::TextComponent> DebugPanelComponent::getText() const
{
	return m_Text;
}
