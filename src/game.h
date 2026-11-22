#pragma once
#include "spaceship.h"
#include "obstacle.h"
#include "alien.h"
#include "mysteryship.h"

class Game
{
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void HandleInput();
	bool run;
	int lives;
	int highScore;
	int score;
	Music music;


private:
	Sound explosionSound;
	void DeleteInactiveLasers();
	std::vector<Obstacle> CreateObstacles();
	std::vector<Alien> CreateAliens();
	void MoveAliens();
	void MoveDownAliens(int distance);
	void AlienShootLaser();
	void CheckForCollisions();
	void GameOver();
	void Reset();
	void CheckForHighScore();
	void InitGame();
	void SaveHighScoreToFile(int highScore);
	int LoadHighScoreFromFile();
	Spaceship spaceship;
	std::vector<Obstacle> obstacles;
	std::vector<Alien> aliens;
	std::vector<Laser> alienLasers;
	int aliensDirection;
	constexpr static float alienLaserShootInterval = 0.35;
	float timeLastAlienFired;
	MysteryShip mysteryShip;
	float mysteryShipSpawnInterval;
	float timeLastSpawn;
	
};