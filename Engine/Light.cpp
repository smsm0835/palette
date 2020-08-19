#include "stdafx.h"
#include "Light.h"

Light::Light() {
	light = new Sprite("Resources/Image/light.png");
	AddChild(light);
	setScale(2, 4);
	setScalingCenter(0, light->getHeight());
	rect = light->getRect();
}

Light::~Light() {

}

void Light::Update(float dTime) {
	/*Object::Update(dTime);
	setPos(getPosX() - RUNNING_SPEED * dTime, getPosY());*/
}

void Light::Render() {
	Object::Render();
	light->Render();
}