#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include <list>
//Object Headers
#include "Number.h"
#include "Player.h"
#include "Background.h"
#include "Bridge.h"
#include "Coin.h"
#include "Obstacle.h"

#include "GameScene2.h"

class GameScene : public Scene
{
private :
	int score, coinCounter;
	bool backgroundInstatiate, bridgeInstantiate, obstacleInstantiate,isRight;
	float coinInstDelayTimer,obstacleInstDelayTimer;

	Background* background;
	std::list<Coin*> coinList;
	Bridge* bridge;
	Obstacle* obstacle;
	Number *numArray[4];
	Player* player;
public :
	GameScene();
	~GameScene();

	void Render();
	void Update(float dTime);

	void CollisionCheck();
	void OptimizationObject();
	void InstantiateObject();
	
	void TimerSetting(float dTime);
	void UISetting();
};