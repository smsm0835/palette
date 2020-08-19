#pragma once
#include "Box.h"
#include "Sprite.h"

enum class BOX{
	STORM,
	BUILDING,
}; //Ãß°¡

class Box : public Object
{
private:
	Sprite* box;
	BOX boxes;
public:
	Box();
	Box(int kind);
	~Box();

	void Update(float dTime);
	void Render();
};