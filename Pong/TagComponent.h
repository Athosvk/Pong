#pragma once
#include <string>
#include <Artifact/Core/Component.h>

class TagComponent : public Artifact::Component
{
public:
    std::string Tag = "";

public:
    TagComponent(Artifact::GameObject a_GameObject);
};

