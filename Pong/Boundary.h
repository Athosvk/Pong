#pragma once
#include <Artifact/Core/GameObject.h>

class Boundary : public Artifact::GameObject
{
public:
	Boundary(unsigned a_ID, Artifact::EntitySystem& a_EntitySystem);
};

