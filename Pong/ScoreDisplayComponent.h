#pragma once
#include <Artifact/Core/Component.h>

#include "ScoreComponent.h"

namespace Artifact
{
	class TextComponent;
}

class ScoreDisplayComponent : public Artifact::Component
{
	Artifact::ComponentHandle<ScoreComponent> m_Score = Artifact::ComponentHandle<ScoreComponent>::NullHandle;
public:
	Artifact::ComponentHandle<Artifact::TextComponent> Text;

public:
	ScoreDisplayComponent(Artifact::GameObject a_GameObject);

	void setScoreComponent(Artifact::ComponentHandle<ScoreComponent> a_ScoreComponent);
	Artifact::ComponentHandle<ScoreComponent> getScoreComponent() const;
};

