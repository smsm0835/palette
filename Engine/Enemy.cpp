#include "stdafx.h"
#include "Enemy.h"
Enemy::Enemy() {
	gravity = 9.8;
	color = 0;
	isRight = false;
	isWater = true;

	EnemyAnimation = new Animation(10);
	EnemyAnimation->AddFrame("Resources/Image/player-stop.png");
	EnemyAnimation->AddFrame("Resources/Image/player-run.png");

	EnemyAnimationB = new Animation(10);
	EnemyAnimationB->AddFrame("Resources/Image/enemy-stop.png");
	EnemyAnimationB->AddFrame("Resources/Image/enemy-run.png");

	EnemyAnimationY = new Animation(10);
	EnemyAnimationY->AddFrame("Resources/Image/enemy1-stop.png");
	EnemyAnimationY->AddFrame("Resources/Image/enemy1-run.png");

	EnemyAnimationBB = new Animation(10);
	EnemyAnimationBB->AddFrame("Resources/Image/enemy3-stop.png");
	EnemyAnimationBB->AddFrame("Resources/Image/enemy3-run.png");

	EnemyAnimation1 = new Animation(10);
	EnemyAnimationBB->AddFrame("Resources/Image/enemy4-stop.png");
	EnemyAnimationBB->AddFrame("Resources/Image/enemy4-run.png");

	EnemyAnimation2 = new Animation(10);
	EnemyAnimationBB->AddFrame("Resources/Image/enemy5-stop.png");
	EnemyAnimationBB->AddFrame("Resources/Image/enemy5-run.png");

	EnemyAnimation3 = new Animation(10);
	EnemyAnimationBB->AddFrame("Resources/Image/enemy6-stop.png");
	EnemyAnimationBB->AddFrame("Resources/Image/enemy6-run.png");

	AddChild(EnemyAnimation);

	AddChild(EnemyAnimationB);

	AddChild(EnemyAnimationY);

	AddChild(EnemyAnimationBB);

	AddChild(EnemyAnimation1);

	AddChild(EnemyAnimation2);

	AddChild(EnemyAnimation3);

	EnemyAnimation->setScale(0.5, 0.5);

	EnemyAnimationB->setScale(0.5, 0.5);

	EnemyAnimationY->setScale(0.5, 0.5);

	EnemyAnimationBB->setScale(0.5, 0.5);

	EnemyAnimation1->setScale(0.5, 0.5);

	EnemyAnimation2->setScale(0.5, 0.5);

	EnemyAnimation3->setScale(0.5, 0.5);

	rect = EnemyAnimation->getRect();
	rect = EnemyAnimationB->getRect();
	rect = EnemyAnimationY->getRect();
	rect = EnemyAnimationBB->getRect();
}

Enemy::Enemy(int i) {
	gravity = 9.8;
	color = i;
	isRight = false;
	isWater = true;

	EnemyAnimation = new Animation(10);
	EnemyAnimation->AddFrame("Resources/Image/player-stop.png");
	EnemyAnimation->AddFrame("Resources/Image/player-run.png");

	EnemyAnimationB = new Animation(10);
	EnemyAnimationB->AddFrame("Resources/Image/enemy-stop.png");
	EnemyAnimationB->AddFrame("Resources/Image/enemy-run.png");

	EnemyAnimationY = new Animation(10);
	EnemyAnimationY->AddFrame("Resources/Image/enemy1-stop.png");
	EnemyAnimationY->AddFrame("Resources/Image/enemy1-run.png");

	EnemyAnimationBB = new Animation(10);
	EnemyAnimationBB->AddFrame("Resources/Image/enemy3-stop.png");
	EnemyAnimationBB->AddFrame("Resources/Image/enemy3-run.png");

	EnemyAnimation1 = new Animation(10);
	EnemyAnimation1->AddFrame("Resources/Image/enemy4-stop.png");
	EnemyAnimation1->AddFrame("Resources/Image/enemy4-run.png");

	EnemyAnimation2 = new Animation(10);
	EnemyAnimation2->AddFrame("Resources/Image/enemy5-stop.png");
	EnemyAnimation2->AddFrame("Resources/Image/enemy5-run.png");

	EnemyAnimation3 = new Animation(10);
	EnemyAnimation3->AddFrame("Resources/Image/enemy6-stop.png");
	EnemyAnimation3->AddFrame("Resources/Image/enemy6-run.png");

	AddChild(EnemyAnimation);

	AddChild(EnemyAnimationB);

	AddChild(EnemyAnimationY);

	AddChild(EnemyAnimationBB);

	AddChild(EnemyAnimation1);

	AddChild(EnemyAnimation2);

	AddChild(EnemyAnimation3);

	EnemyAnimation->setScale(0.5, 0.5);

	EnemyAnimationB->setScale(0.5, 0.5);

	EnemyAnimationY->setScale(0.5, 0.5);

	EnemyAnimationBB->setScale(0.5, 0.5);

	EnemyAnimation1->setScale(0.5, 0.5);

	EnemyAnimation2->setScale(0.5, 0.5);

	EnemyAnimation3->setScale(0.5, 0.5);

	rect = EnemyAnimation->getRect();
}

Enemy::~Enemy() {

}

bool Enemy::getRight() {
	return isRight;
}

void Enemy::changeRight(bool i) {
	isRight = i;
}

bool Enemy::getWater() {
	return isWater;
}

void Enemy::changeWater(bool i) {
	isWater = i;
}

int Enemy::getColor() {
	return color;
}

void Enemy::changeColor(int i) {
	color = i;
}

void Enemy::Render() {
	if (isWater) {
		Object::Render();
		if (color == 0)
			EnemyAnimation->Render();
		else if (color == 1)
			EnemyAnimationB->Render();
		else if (color == 2)
			EnemyAnimationY->Render();
		else if (color == 3)
			EnemyAnimationBB->Render();
		else if (color == 6)
			EnemyAnimation1->Render();
		else if (color == 7)
			EnemyAnimation2->Render();
		else if (color == 8)
			EnemyAnimation3->Render();
	}
	else {
		setPos(getPosX(), getPosY());
	}
}

void Enemy::Update(float dTime) {
	gravity += 9.8f;
	if (isRight == false) {
		setScalingCenter(0, 0);
		setScale(1, 1);
	}
	if (isRight == true) {
		setScalingCenter(25, 0);
		setScale(-1, 1);
	}
	setPos(getPosX(), getPosY() + gravity * dTime);
	if (getPosY() > 460) {
		setPos(getPosX(), 460);
	}

	if (color == 0)
		EnemyAnimation->Update(dTime);
	else if (color == 1)
		EnemyAnimationB->Update(dTime);
	else if (color == 2)
		EnemyAnimationY->Update(dTime);
	else if (color == 3)
		EnemyAnimationBB->Update(dTime);
	else if (color == 6)
		EnemyAnimation1->Update(dTime);
	else if (color == 7)
		EnemyAnimation2->Update(dTime);
	else if (color == 8)
		EnemyAnimation3->Update(dTime);
}