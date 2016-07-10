#include <Artifact/Color.h>
#include <Artifact/Transform.h>
#include <Artifact/Rendering/TextComponent.h>
#include <Artifact/IO/ResourceManager.h>

#include "GameWorld.h"
#include "MovementSystem.h"
#include "Paddle/PlayerInputSystem.h"
#include "Paddle/Paddle.h"
#include "Paddle/PlayerInputComponent.h"
#include "MovementCircleComponent.h"
#include "Ball.h"
#include "ReflectSystem.h"
#include "DebugPanelSystem.h"
#include "DebugPanelComponent.h"
#include "Boundary.h"
#include "ScoringSystem.h"
#include "ScoreDisplaySystem.h"
#include "ScoreDisplayComponent.h"

GameWorld::GameWorld(Artifact::GameTime& a_GameTime, Artifact::Game* a_CurrentGame)
    : World(a_GameTime, a_CurrentGame)
{
    addSystem<PlayerInputSystem>();
    addSystem<MovementSystem>();
	addSystem<ReflectSystem>();
	//addSystem<DebugPanelSystem>();
	addSystem<ScoringSystem>();
	addSystem<ScoreDisplaySystem>();
    initialisePlayers();

    auto movementCircle = m_EntitySystem.createEntity().addComponent<MovementCircleComponent>();
    movementCircle->Radius = 3.0f;
    m_EntitySystem.createEntity<Ball>();
	auto debugPanel = m_EntitySystem.createEntity();
	auto panelComponent = debugPanel.addComponent<DebugPanelComponent>();
	panelComponent->getText()->Font = Artifact::ResourceManager::getFont("Assets/Fonts/Helvetica Bold.ttf");
	panelComponent->getText()->Scaling = 0.2f;
	debugPanel.getComponent<Artifact::Transform>()->setPosition(glm::vec2(-5.f, 3.8f));

	Boundary boundaryLeft = m_EntitySystem.createEntity<Boundary>();
	boundaryLeft.getComponent<Artifact::Transform>()->setPosition(glm::vec2(-5.2f, 0.0f));
	boundaryLeft.getComponent<Artifact::Transform>()->setRotation(90.0f);

	Boundary boundaryRight = m_EntitySystem.createEntity<Boundary>();
	boundaryRight.getComponent<Artifact::Transform>()->setPosition(glm::vec2(5.2f, 0.f));
	boundaryRight.getComponent<Artifact::Transform>()->setRotation(90.0f);

	Boundary boundaryTop = m_EntitySystem.createEntity<Boundary>();
	boundaryTop.getComponent<Artifact::Transform>()->setPosition(glm::vec2(0.f, 4.f));

	Boundary boundaryBottom = m_EntitySystem.createEntity<Boundary>();
	boundaryBottom.getComponent<Artifact::Transform>()->setPosition(glm::vec2(0.f, -4.f));
}

void GameWorld::initialisePlayers()
{
    auto redPaddle = m_EntitySystem.createEntity<Paddle>();
    redPaddle.setColor(Artifact::Color::Red);

    auto bluePaddle = m_EntitySystem.createEntity<Paddle>();
    bluePaddle.setColor(Artifact::Color(0.0f, 0.5f, 1.0f, 1.0f));
    auto bluePaddleInput = bluePaddle.getComponent<PlayerInputComponent>();
	bluePaddle.getComponent<MovementComponent>()->Angle = 180.0f;
    bluePaddleInput->MoveLeftKey = Artifact::KeyCode::A;
    bluePaddleInput->MoveRightKey = Artifact::KeyCode::D;

	Artifact::ComponentHandle<ScoreDisplayComponent> scoreDisplayBlue = m_EntitySystem.createEntity().addComponent<ScoreDisplayComponent>();
	scoreDisplayBlue->setScoreComponent(bluePaddle.getComponent<ScoreComponent>());
	scoreDisplayBlue->getComponent<Artifact::Transform>()->setPosition(glm::vec2(-3.f, 3.f));

	Artifact::ComponentHandle<ScoreDisplayComponent> scoreDisplayRed = m_EntitySystem.createEntity().addComponent<ScoreDisplayComponent>();
	scoreDisplayRed->setScoreComponent(redPaddle.getComponent<ScoreComponent>());
	scoreDisplayRed->getComponent<Artifact::Transform>()->setPosition(glm::vec2(3.f, 3.f));
}
