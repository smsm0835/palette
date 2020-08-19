#pragma once
#include "Object.h"
#include "Sprite.h"

class Wwater : public Object
{
private:
	Sprite* wwater1,*wwater2,*wwater3,*wwater4, * wwater5, * wwater6, * wwater7,*wwater8;
	int color;
public:
	Wwater();
	Wwater(int kind);
	~Wwater();

	int getColor();
	void changeColor(int i);
	void Update(float dTime);
	void Render();
};