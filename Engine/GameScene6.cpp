#include "stdafx.h"
#include "GameScene6.h"
GameScene6::GameScene6() {
	score = 6;
	isBox = false;
	isRight = false;
	isWater = true;
	/*coinCounter = 0;*/


	backgroundInstatiate = false;
	/*bridgeInstantiate = false;*/
	/*obstacleInstantiate = true;

	obstacleInstDelayTimer = 0;*/
	/*coinInstDelayTimer = 0;*/

	Background* background = new Background();
	background->setPos(0, 0);
	backgroundList.push_back(background);
	AddObject(background);

	/*Bridge* bridge = new Bridge();
	bridge->setPos(0, 500);
	bridgeList.push_back(bridge);
	AddObject(bridge);	*/

	for (int i = 0; i < 4; i++) {
		numArray[i] = new Number();
		numArray[i]->setPos(0 + 60 * i, 10);
		AddUI(numArray[i]);
	}
	bridge = new Bridge();
	AddObject(bridge);
	bridge->setPos(0, 550);

	obstacle = new Obstacle();
	AddObject(obstacle);
	obstacle->setPos(900, 460);

	player = new Player();
	AddObject(player);
	player->setPos(0, 460);

	/*enemy = new Enemy(1);
	AddObject(enemy);
	enemy->setPos(375, 460);

	enemy1 = new Enemy(1);
	AddObject(enemy1);
	enemy1->setPos(625, 460);

	water1 = new Water();
	AddObject(water1);
	water1->setPos(250, 0);

	water2 = new Water(0);
	AddObject(water2);
	water2->setPos(500, 0);

	water3 = new Water();
	AddObject(water3);
	water3->setPos(750, 0);*/

	wwater1 = new Wwater();
	AddObject(wwater1);
	wwater1->setPos(300, 540);
	wwater1->setScale(1.5, 1);

	wwater2 = new Wwater();
	AddObject(wwater2);
	wwater2->setPos(600, 540);
	wwater2->setScale(1.5, 1);

	/*box = new Box();
	AddObject(box);
	box->setPos(300, 480);*/
}

GameScene6::~GameScene6() {

}

void GameScene6::Render() {
	for (auto& background : backgroundList) {
		background->Render();
	}
	/*for (auto& bridge : bridgeList) {
		bridge->Render();
	}*/
	/*for (auto& obstacle : obstacleList) {
		obstacle->Render();
	}*/
	/*for (auto& coin : coinList) {
		coin->Render();
	}*/
	bridge->Render();

	obstacle->Render();

	if (!isBox)
		player->Render();

	/*enemy->Render();

	enemy1->Render();

	water1->Render();

	water2->Render();

	water3->Render();*/

	wwater1->Render();

	wwater2->Render();

	/*box->Render();*/

	for (int i = 0; i < 4; i++) {
		numArray[i]->Render();
	}
}

void GameScene6::Update(float dTime) {
	Scene::Update(dTime);
	UISetting();
	TimerSetting(dTime);
	OptimizationObject();
	InstantiateObject();
	EnemyCheck(dTime);
	EnemyScale();
	CollisionCheck();
}

void GameScene6::TimerSetting(float dTime) {
	/*coinInstDelayTimer += dTime;*/
	/*obstacleInstDelayTimer += dTime;*/
}

void GameScene6::UISetting() {
	numArray[0]->setNum(score / 1000);
	numArray[1]->setNum(score / 100 % 10);
	numArray[2]->setNum(score / 10 % 10);
	numArray[3]->setNum(score % 10);
}

void GameScene6::OptimizationObject() {
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);
			backgroundInstatiate = false;
			/*obstacleInstantiate = false;*/
			if (iter == backgroundList.end()) {
				break;
			}
		}
	}


	/*for (auto iter = bridgeList.begin(); iter != bridgeList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = bridgeList.erase(iter);
			bridgeInstantiate = false;
			if (iter == bridgeList.end()) {
				break;
			}
		}
	}*/

	//for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
	//	if ((*iter)->getPosX() < -SCREEN_WIDTH) {
	//		RemoveObject((*iter));
	//		SAFE_DELETE(*iter);
	//		iter = coinList.erase(iter);
	//		if (iter == coinList.end()) {
	//			break;
	//		}
	//	}
	//}

	/*for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = obstacleList.erase(iter);

			if (iter == obstacleList.end()) {
				break;

			}
		}
	}*/
}

void GameScene6::CollisionCheck() {
	/*for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		if (player->IsCollisionRect((*iter))) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);

			if ((*iter)->getIsRed()) {
				score += 10;
			}
			else {
				score += 1;
			}

			score %= 10000;

			if (iter == coinList.end()) {
				break;
			}
		}
	}*/

	/*if (player->IsCollisionRect((box)) && !isBox && inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
		isBox = true;
	}
	else if (isBox) {
		player->setPos(box->getPosX(), box->getPosY());
		if (player->IsCollisionRect((box)) && isBox && inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
			isBox = false;
		}
	}*/
	/*if (player->IsCollisionRect((water1)) && water1->getColor() == 5 && !isBox) {
		sceneManager->ChangeScene(new GameScene6());
		return;
	}
	if (player->IsCollisionRect((water2)) && water2->getColor() == 5 && !isBox) {
		sceneManager->ChangeScene(new GameScene6());
		return;
	}
	if (player->IsCollisionRect((water3)) && water3->getColor() == 5 && !isBox) {
		sceneManager->ChangeScene(new GameScene6());
		return;
	}*/

	if (player->IsCollisionRect((wwater1)) && wwater1->getColor() == 5) {
		sceneManager->ChangeScene(new GameScene6());
		return;
	}
	if (player->IsCollisionRect((wwater2)) && wwater2->getColor() == 5) {
		sceneManager->ChangeScene(new GameScene6());
		return;
	}

	/*if (enemy->IsCollisionRect((water1)) && water1->getColor() == 5) {
		enemy->changeWater(false);
	}
	else if (enemy->IsCollisionRect((water1)) && !(water1->getColor() == 5)) {
		enemy->changeColor(water1->getColor());
	}
	if (enemy->IsCollisionRect((water2)) && water2->getColor() == 5) {
		enemy->changeWater(false);
	}
	else if (enemy->IsCollisionRect((water2)) && !(water2->getColor() == 5)) {
		enemy->changeColor(water2->getColor());
	}
	if (enemy->IsCollisionRect((water3)) && water3->getColor() == 5) {
		enemy->changeWater(false);
	}
	else if (enemy->IsCollisionRect((water3)) && !(water3->getColor() == 5)) {
		enemy->changeColor(water3->getColor());
	}
	if (enemy1->IsCollisionRect((water1)) && water1->getColor() == 5) {
		enemy1->changeWater(false);
	}
	else if (enemy1->IsCollisionRect((water1)) && !(water1->getColor() == 5)) {
		enemy1->changeColor(water1->getColor());
	}
	if (enemy1->IsCollisionRect((water2)) && water2->getColor() == 5) {
		enemy1->changeWater(false);
	}
	else if (enemy1->IsCollisionRect((water2)) && !(water2->getColor() == 5)) {
		enemy1->changeColor(water2->getColor());
	}
	if (enemy1->IsCollisionRect((water3)) && water3->getColor() == 5) {
		enemy1->changeWater(false);
	}
	else if (enemy1->IsCollisionRect((water3)) && !(water3->getColor() == 5)) {
		enemy1->changeColor(water3->getColor());
	}
	if (player->IsCollisionRect((enemy)) && !(player->getColor() == enemy->getColor()) && !isBox && enemy->getWater()) {
		sceneManager->ChangeScene(new GameScene6());
		return;
	}
	if (player->IsCollisionRect((enemy1)) && !(player->getColor() == enemy1->getColor()) && !isBox && enemy->getWater()) {
		sceneManager->ChangeScene(new GameScene6());
		return;
	}*/
	/*for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {*/
	if (player->IsCollisionRect((obstacle))) {
		sceneManager->ChangeScene(new GameScene7());
		return;
	}
	/*}*/
}

void GameScene6::EnemyScale() {
	/*if (player->getPosX() > enemy->getPosX()) {
		std::cout << "神";
		enemy->changeRight(false);
	}
	else if (player->getPosX() < enemy->getPosX()) {
		std::cout << "神";
		enemy->changeRight(true);
	}
	if (player->getPosX() > enemy1->getPosX()) {
		std::cout << "神";
		enemy1->changeRight(false);
	}
	else if (player->getPosX() < enemy1->getPosX()) {
		std::cout << "神";
		enemy1->changeRight(true);
	}*/
}

void GameScene6::EnemyCheck(float dTime) {
	/*if (!isBox && !(player->getColor() == enemy->getColor())) {
		if (enemy->getPosX() - player->getPosX() < 250 && enemy->getPosX() - player->getPosX() > -250) {
			if (enemy->getPosX() > player->getPosX())
				enemy->setPos(enemy->getPosX() - 100 * dTime, 460);
			else if (enemy->getPosX() < player->getPosX())
				enemy->setPos(enemy->getPosX() + 100 * dTime, 460);
		}
	}
	else {
		enemy->setPos(enemy->getPosX(), 460);
	}
	if (!isBox && !(player->getColor() == enemy1->getColor())) {
		if (enemy1->getPosX() - player->getPosX() < 250 && enemy1->getPosX() - player->getPosX() > -250) {
			if (enemy1->getPosX() > player->getPosX())
				enemy1->setPos(enemy1->getPosX() - 100 * dTime, 460);
			else if (enemy1->getPosX() < player->getPosX())
				enemy1->setPos(enemy1->getPosX() + 100 * dTime, 460);
		}
	}
	else {
		enemy1->setPos(enemy1->getPosX(), 460);
	}
	enemy->setPos(enemy->getPosX() - 300 * dTime, player->getPosY());*/
}

void GameScene6::InstantiateObject() {
	if (!backgroundInstatiate) {
		Background* background = new Background();
		background->setPos(SCREEN_WIDTH - 20, 0);
		backgroundList.push_back(background);
		AddObject(background);
		backgroundInstatiate = true;
	}

	//if (!bridgeInstantiate) {
	//	Bridge* bridge = new Bridge();
	//	bridge->setPos(SCREEN_WIDTH - 20, 500);
	//	bridgeList.push_back(bridge);
	//	AddObject(bridge);
	//	bridgeInstantiate = true;
	//}

	//if (!obstacleInstantiate) {
	//	if (obstacleInstDelayTimer > 1.f) {
	//		obstacleInstDelayTimer = 0;
	//		/*coinCounter = 4;*/
	//		Obstacle* obstacle = new Obstacle(rand() % 2);
	//		obstacle->setPos(SCREEN_WIDTH + 50, 400);
	//		AddObject(obstacle);
	//		obstacleList.push_back(obstacle);
	//		obstacleInstantiate = true;
	//	}
	//}

	//if (coinCounter > 0) {
	//	if (coinInstDelayTimer > 0.1f) {
	//		coinCounter--;
	//		coinInstDelayTimer = 0;
	//		Coin* coin = new Coin(true);
	//		coin->setPos(SCREEN_WIDTH, 300);
	//		AddObject(coin);
	//		coinList.push_back(coin);
	//	}
	//}
	//else {
	//	if (coinInstDelayTimer > 0.1f) {
	//		coinInstDelayTimer = 0;
	//		Coin* coin = new Coin(false);
	//		coin->setPos(SCREEN_WIDTH, 400);
	//		AddObject(coin);
	//		coinList.push_back(coin);
	//	}
	//}
}
