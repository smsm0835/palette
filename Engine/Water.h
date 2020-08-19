#pragma once
#include "Object.h"
#include "Sprite.h"

class Water : public Object
{
private:
	Sprite* water1, *water2, *water3, *water4,*water5, * water6, * water7, * water8;
	int color;
	float gravity;
	bool doubleJump, isJump;

public:
	Water();
	Water(int i);
	~Water();
	int getColor();
	void changeColor(int i);
	void Render();
	void Update(float dTime);

};