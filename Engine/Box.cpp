#include "stdafx.h"
#include "Box.h"

Box::Box() {
	box = new Sprite("Resources/Image/Box.png");
	AddChild(box);
	box->setScale(2, 2);
	rect = box->getRect();
}


Box::~Box() {

}

void Box::Update(float dTime) {
	/*Object::Update(dTime);
	setPos(getPosX() - RUNNING_SPEED * dTime, getPosY());*/
}

void Box::Render() {
	Object::Render();
	box->Render();
}