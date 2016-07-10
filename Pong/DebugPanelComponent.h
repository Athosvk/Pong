#pragma once
#include <Artifact/Core/Component.h>
#include <Artifact/Input/Keycode.h>

namespace Artifact
{
	class TextComponent;
}

class DebugPanelComponent : public Artifact::Component
{
private:
	Artifact::ComponentHandle<Artifact::TextComponent> m_Text;
public:
	Artifact::KeyCode HideKey = Artifact::KeyCode::Space;
public:
	DebugPanelComponent(Artifact::GameObject a_GameObject);

	Artifact::ComponentHandle<Artifact::TextComponent> getText() const;
};

