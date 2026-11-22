#pragma once
#include "raylib.h"
#include "laser.h"
#include <vector>
class Spaceship
{
public: 
	Spaceship();
	~Spaceship();
	void Draw();
	void MoveLeft();
	void MoveRight();
	Rectangle getRect();
	void Reset();

	void FireLaser();
	std::vector<Laser> lasers;
private:
	Texture2D image;
	Vector2 position;
	double lastFireTime;
	Sound laserSound;
};