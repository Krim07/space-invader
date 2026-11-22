#include "mysteryship.h"

MysteryShip::MysteryShip()
{
	image = LoadTexture("C://Users//SAMUEL//Downloads//mystery.png");
	alive = false;
}

MysteryShip::~MysteryShip()
{
	UnloadTexture(image);
}

void MysteryShip::Update()
{
	if (alive)
	{
		position.x += speed;
		if (position.x > GetScreenWidth() - image.width -25 || position.x < 25)
		{
			alive = false;
		}
	}
}

void MysteryShip::Draw()
{
	if (alive)
	{
		DrawTextureV(image, position, WHITE);
	}
}

void MysteryShip::Spawn()
{
	int side = GetRandomValue(0, 1);
	position.y = 90;
	if (side == 0) {
		position.x = 25;
		speed = 3;
	}
	else
	{
		position.x = GetScreenWidth() - image.width - 25;
		speed = -3;
	}
	alive = true;
}

Rectangle MysteryShip::getRect()
{
	if (alive)
	{
		return { position.x, position.y, (float)image.width, (float)image.height };
	}
	else
	{
		return { position.x, position.y, 0,0 };
	}
	
}

