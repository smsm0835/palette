#pragma once
#include "Object.h"
#include "Animation.h"

class Enemy : public Object
{
private:
	Animation *EnemyAnimation,*EnemyAnimationB,*EnemyAnimationY,*EnemyAnimationBB, * EnemyAnimation1, * EnemyAnimation2, * EnemyAnimation3, * EnemyAnimation4;
	int color;
	float gravity;
	bool doubleJump, isJump,isWater,isRight;

public:
	Enemy();
	Enemy(int i);
	~Enemy();
	bool getRight();
	void changeRight(bool i);
	bool getWater();
	void changeWater(bool i);
	int getColor();
	void changeColor(int i);
	void Render();
	void Update(float dTime);

};