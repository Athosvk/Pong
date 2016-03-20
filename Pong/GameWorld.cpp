#include <Artifact/Color.h>
#include <Artifact/Transform.h>

#include "GameWorld.h"
#include "MovementSystem.h"
#include "Paddle/PlayerInputSystem.h"
#include "Paddle/Paddle.h"
#include "Paddle/PlayerInputComponent.h"

GameWorld::GameWorld(Artifact::GameTime& a_GameTime, Artifact::Game* a_CurrentGame)
    : World(a_GameTime, a_CurrentGame)
{
    addSystem<PlayerInputSystem>();
    addSystem<MovementSystem>();
    initialisePlayers();
}

void GameWorld::initialisePlayers()
{
    auto redPaddle = m_EntitySystem.createEntity<Paddle>();
    redPaddle.setColor(Artifact::Color::Red);
    redPaddle.getComponent<Artifact::Transform>()->setPosition(glm::vec2(-4.5f, 0.0f));

    auto bluePaddle = m_EntitySystem.createEntity<Paddle>();
    bluePaddle.setColor(Artifact::Color::Blue);
    bluePaddle.getComponent<Artifact::Transform>()->setPosition(glm::vec2(4.5f, 0.0f));
    auto bluePaddleInput = bluePaddle.getComponent<PlayerInputComponent>();
    bluePaddleInput->MoveLeftKey = Artifact::KeyCode::A;
    bluePaddleInput->MoveRightKey = Artifact::KeyCode::D;
}
