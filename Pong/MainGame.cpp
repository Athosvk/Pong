#include "MainGame.h"
#include "GameWorld.h"

MainGame::MainGame()
    : Game(1024, 768, 0, "Pong 360")
{
    loadWorld<GameWorld>();
}