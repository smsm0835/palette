#pragma once
#include "Object.h"
#include "Sprite.h"

class Light : public Object
{
private:
	Sprite* light;
public:
	Light();
	~Light();

	void Update(float dTime);
	void Render();
};