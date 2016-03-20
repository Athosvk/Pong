#include <Artifact/Color.h>
#include <Artifact/Transform.h>

#include "GameWorld.h"
#include "MovementSystem.h"
#include "Paddle/PlayerInputSystem.h"
#include "Paddle/Paddle.h"
#include "Paddle/PlayerInputComponent.h"
#include "MovementCircleComponent.h"
#include "Ball.h"

GameWorld::GameWorld(Artifact::GameTime& a_GameTime, Artifact::Game* a_CurrentGame)
    : World(a_GameTime, a_CurrentGame)
{
    addSystem<PlayerInputSystem>();
    addSystem<MovementSystem>();
    initialisePlayers();

    auto movementCircle = m_EntitySystem.createEntity().addComponent<MovementCircleComponent>();
    movementCircle->Radius = 3.0f;
    m_EntitySystem.createEntity<Ball>();
}

void GameWorld::initialisePlayers()
{
    auto redPaddle = m_EntitySystem.createEntity<Paddle>();
    redPaddle.setColor(Artifact::Color::Red);

    auto bluePaddle = m_EntitySystem.createEntity<Paddle>();
    bluePaddle.setColor(Artifact::Color::Blue);
    auto bluePaddleInput = bluePaddle.getComponent<PlayerInputComponent>();
    bluePaddleInput->MoveLeftKey = Artifact::KeyCode::A;
    bluePaddleInput->MoveRightKey = Artifact::KeyCode::D;
}
