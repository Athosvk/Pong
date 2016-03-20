#include <Artifact/Color.h>

#include "GameWorld.h"
#include "MovementSystem.h"
#include "Paddle/PlayerInputSystem.h"
#include "Paddle/Paddle.h"

GameWorld::GameWorld(Artifact::GameTime& a_GameTime, Artifact::Game* a_CurrentGame)
    : World(a_GameTime, a_CurrentGame)
{
    addSystem<PlayerInputSystem>();
    addSystem<MovementSystem>();

    auto redPaddle = m_EntitySystem.createEntity<Paddle>();
    redPaddle.setColor(Artifact::Color::Red);
    auto bluePaddle = m_EntitySystem.createEntity<Paddle>();
    bluePaddle.setColor(Artifact::Color::Blue);
}
