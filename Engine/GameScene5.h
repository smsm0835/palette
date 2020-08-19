#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include <list>
//Object Headers
#include "Number.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Bridge.h"
#include "Coin.h"
#include "Obstacle.h"
#include "Box.h"
#include "Water.h"

#include "GameScene6.h"

class GameScene5 : public Scene
{
private:
	int score, coinCounter;
	bool backgroundInstatiate, bridgeInstantiate, obstacleInstantiate, isBox, isRight,isWater;
	float coinInstDelayTimer, obstacleInstDelayTimer;

	std::list<Background*> backgroundList;
	std::list<Coin*> coinList;
	Bridge* bridge;
	Obstacle* obstacle;
	Number* numArray[4];
	Player* player;
	Enemy* enemy,*enemy1;
	Box* box;
	Water* water1, *water2, *water3;
public:
	GameScene5();
	~GameScene5();

	void Render();
	void Update(float dTime);

	void EnemyScale();
	void CollisionCheck();
	void EnemyCheck(float dTime);
	void OptimizationObject();
	void InstantiateObject();

	void TimerSetting(float dTime);
	void UISetting();
};

