#pragma once
#include "Object.h"
#include "Animation.h"

class Player : public Object
{
private :
	Animation* playerAnimation, *playerAnimation1, *playerAnimation2, *playerAnimation3, * playerAnimation4, * playerAnimation5, * playerAnimation6;
	int color;
	float gravity;
	bool doubleJump, isJump,isRight;

public :
	Player();
	~Player();

	void changeColor(int i);
	int getColor();
	void Render();
	void Update(float dTime);

};