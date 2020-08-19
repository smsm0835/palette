#include "stdafx.h"
#include "Wwater.h"

Wwater::Wwater() {
	color = 5;
	wwater1 = new Sprite("Resources/Image/wwater1.png");
	AddChild(wwater1);

	wwater2 = new Sprite("Resources/Image/wwater2.png");
	AddChild(wwater2);

	wwater3 = new Sprite("Resources/Image/wwater3.png");
	AddChild(wwater3);

	wwater4 = new Sprite("Resources/Image/wwater4.png");
	AddChild(wwater4);

	wwater5 = new Sprite("Resources/Image/wwater5.png");
	AddChild(wwater5);

	wwater6 = new Sprite("Resources/Image/wwater6.png");
	AddChild(wwater6);

	wwater7 = new Sprite("Resources/Image/wwater7.png");
	AddChild(wwater7);

	wwater8 = new Sprite("Resources/Image/wwater8.png");
	AddChild(wwater8);

	rect = wwater1->getRect();
}

Wwater::~Wwater() {

}

int Wwater::getColor() {
	return color;
}

void Wwater::changeColor(int i) {
	if (color == 0 && !(color == i)) {
		if (i == 1) {
			color = 6;
		}
		else if (i == 2) {
			color = 7;
		}
	}
	else if (color == 1 && !(color == i)) {
		if (i == 0) {
			color = 6;
		}
		else if (i == 2) {
			color = 8;
		}
	}
	else if (color == 2 && !(color == i)) {
		if (i == 0) {
			color = 7;
		}
		else if (i == 1) {
			color = 8;
		}
	}
	else if (color == 6 && !(color == i)) {
		color = 3;
	}
	else if (color == 7 && !(color == i)) {
		color = 3;
	}
	else if (color == 8 && !(color == i)) {
		color = 3;
	}
	else if (color == 3 && i == 5) {
		color = 0;
	}
	else {
		if (!(color == 3)) {
			color = i;
		}
	}
}

void Wwater::Update(float dTime) {
	/*Object::Update(dTime);
	setPos(getPosX() - RUNNING_SPEED * dTime, getPosY());*/
}

void Wwater::Render() {
	Object::Render();
	if (color == 5) 
	wwater1->Render();
	else if (color == 0)
		wwater2->Render();
	else if (color == 1)
		wwater3->Render();
	else if (color == 2)
		wwater4->Render();
	else if (color == 3)
		wwater8->Render();
	else if (color == 6)
		wwater5->Render();
	else if (color == 7)
		wwater6->Render();
	else if (color == 8)
		wwater7->Render();
}