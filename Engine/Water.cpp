#include "stdafx.h"
#include "Water.h"
Water::Water() {
	gravity = rand() % 100 + 1;
	color = 5;
	water1 = new Sprite("Resources/Image/water.png");
	water2 = new Sprite("Resources/Image/water2.png");
	water3 = new Sprite("Resources/Image/water3.png");
	water4 = new Sprite("Resources/Image/water4.png");

	AddChild(water1);

	AddChild(water2);

	AddChild(water3);

	AddChild(water4);

	rect = water1->getRect();
}

Water::Water(int i) {
	gravity = rand() % 100 + 1;
	color = i;
	water1 = new Sprite("Resources/Image/water.png");
	water2 = new Sprite("Resources/Image/water2.png");
	water3 = new Sprite("Resources/Image/water3.png");
	water4 = new Sprite("Resources/Image/water4.png");
	water5 = new Sprite("Resources/Image/water5.png");

	AddChild(water1);

	AddChild(water2);

	AddChild(water3);

	AddChild(water4);

	AddChild(water5);

	rect = water1->getRect();
}

Water::~Water() {

}

int Water::getColor() {
	return color;
}

void Water::changeColor(int i) {
	color = i;
}

void Water::Render() {
	Object::Render();
	if (color == 5)
		water1->Render();
	else if (color == 0)
		water2->Render();
	else if (color == 1)
		water3->Render();
	else if (color == 2)
		water5->Render();
	else if (color == 3)
		water4->Render();
}

void Water::Update(float dTime) {
	gravity += 9.8f;

	setPos(getPosX(), getPosY() + gravity * dTime);
	if (getPosY() > 1024) {
		setPos(getPosX(), 0);
		gravity = rand() % 100 + 1;
	}

	water1->Update(dTime);
}