#include "stdafx.h"
#include "Player.h"

Player::Player() {
	isJump = false;
	doubleJump = false;
	gravity = 9.8;
	color = 0;
	isRight = false;

	playerAnimation = new Animation(10);
	playerAnimation->AddFrame("Resources/Image/player-stop.png");
	playerAnimation->AddFrame("Resources/Image/player-run.png");

	AddChild(playerAnimation);

	playerAnimation->setScale(0.5, 0.5);

	playerAnimation1 = new Animation(10);
	playerAnimation1->AddFrame("Resources/Image/enemy-stop.png");
	playerAnimation1->AddFrame("Resources/Image/enemy-run.png");

	AddChild(playerAnimation1);

	playerAnimation1->setScale(0.5, 0.5);

	playerAnimation2 = new Animation(10);
	playerAnimation2->AddFrame("Resources/Image/enemy1-stop.png");
	playerAnimation2->AddFrame("Resources/Image/enemy1-run.png");

	AddChild(playerAnimation2);

	playerAnimation2->setScale(0.5, 0.5);

	playerAnimation3 = new Animation(10);
	playerAnimation3->AddFrame("Resources/Image/enemy3-stop.png");
	playerAnimation3->AddFrame("Resources/Image/enemy3-run.png");

	AddChild(playerAnimation3);

	playerAnimation3->setScale(0.5, 0.5);

	playerAnimation4 = new Animation(10);
	playerAnimation4->AddFrame("Resources/Image/enemy4-stop.png");
	playerAnimation4->AddFrame("Resources/Image/enemy4-run.png");

	AddChild(playerAnimation4);

	playerAnimation4->setScale(0.5, 0.5);

	playerAnimation5 = new Animation(10);
	playerAnimation5->AddFrame("Resources/Image/enemy5-stop.png");
	playerAnimation5->AddFrame("Resources/Image/enemy5-run.png");

	AddChild(playerAnimation5);

	playerAnimation5->setScale(0.5, 0.5);

	playerAnimation6 = new Animation(10);
	playerAnimation6->AddFrame("Resources/Image/enemy6-stop.png");
	playerAnimation6->AddFrame("Resources/Image/enemy6-run.png");

	AddChild(playerAnimation6);

	playerAnimation6->setScale(0.5, 0.5);

	rect = playerAnimation->getRect();
}

Player::~Player() {

}

void Player::Render() {
	Object::Render();
	if (color == 0)
		playerAnimation->Render();
	else if (color == 1)
		playerAnimation1->Render();
	else if (color == 2)
		playerAnimation2->Render();
	else if (color == 3)
		playerAnimation3->Render();
	else if (color == 6)
		playerAnimation4->Render();
	else if (color == 7)
		playerAnimation5->Render();
	else if (color == 8)
		playerAnimation6->Render();
}

int Player::getColor() {
	return color;
}

void Player::changeColor(int i) {
	color = i;
}

void Player::Update(float dTime) {
	gravity += 9.8f;

	setPos(getPosX(), getPosY() + gravity * dTime);
	if (isJump) {
		setPos(getPosX(), getPosY() - 300 * dTime);
		if (doubleJump) {
			setPos(getPosX(), getPosY() - 300 * dTime);
		}
		if (inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
			doubleJump = true;
		}
	}
	if (getPosY() > 460) {
		setPos(getPosX(), 460);
		doubleJump = false;
		isJump = false;
	}
	if (inputManager->GetKeyState(VK_RIGHT) == KEY_DOWN&&isRight) {
		isRight = false;
		setScale(1, 1);
		setScalingCenter(0, 0);
	}
	if (inputManager->GetKeyState(VK_RIGHT) == KEY_ON) {
		if (color == 3)
			setPos(getPosX() +100 * dTime, getPosY());
		else
			setPos(getPosX() + 200 * dTime, getPosY());
	}
	if (inputManager->GetKeyState(VK_LEFT) == KEY_DOWN&&!isRight) {
		isRight = true;
		setScale(-1, 1);
		setScalingCenter(25, 0);
	}
	if (inputManager->GetKeyState(VK_LEFT) == KEY_ON) {
		if (getPosX() > 0) {
			if(color==3)
				setPos(getPosX() - 100 * dTime, getPosY());
			else
			setPos(getPosX() - 200 * dTime, getPosY());
		}
	}

	if (inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
		if (getPosY() == 460) {
			isJump = true;
			gravity = 0;
		}
	}

	if (color == 0)
		playerAnimation->Update(dTime);
	else if (color == 1)
		playerAnimation1->Update(dTime);
	else if (color == 2)
		playerAnimation2->Update(dTime);
	else if (color == 3)
		playerAnimation3->Update(dTime);
	else if (color == 6)
		playerAnimation4->Update(dTime);
	else if (color == 7)
		playerAnimation5->Update(dTime);
	else if (color == 8)
		playerAnimation6->Update(dTime);
}