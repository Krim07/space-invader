#include "raylib.h"
#include "game.h"
#include <string>

std::string FormatWithLeadingZeros(int number, int width)
{
	std::string numberText = std::to_string(number);
	int leadingZeros = 5 - numberText.length();
	return numberText = std::string(leadingZeros, '0') + numberText;
}
int main()
{
	int offset = 50;
	int windowWidth = 750;
	int windowHeight = 700;
	InitWindow(windowWidth + offset, windowHeight + 2 * offset, "Space Invaders C++");
	InitAudioDevice();
	Texture2D spaceshipImage = LoadTexture("C://RAYLIB 1//space invader//pic//spaceship.png");
	SetTargetFPS(60);
	Game game;
	
	while (!WindowShouldClose())
	{
		UpdateMusicStream(game.music);
		game.HandleInput();	
		game.Update();		
		BeginDrawing();
		ClearBackground(DARKGRAY);	
		DrawRectangleRoundedLinesEx({ 10, 10, 780, 780}, 0.18f, 20, 2, YELLOW);
		DrawLineEx({ 25, 730 }, { 775, 730 }, 3, YELLOW);
		
		if (game.run) {
			DrawText("LEVEL 01", 570, 740, 32, YELLOW);
		}
		else
		{
			DrawText("GAME OVER", 570, 740, 32, YELLOW);
		}
		float x = 50;
		for (int i = 0; i < game.lives; i++)
		{
			DrawTextureV(spaceshipImage, {x, 745}, WHITE);
			x += 50;
		}
		DrawText("Score: " , 50, 15, 33, YELLOW);
		std::string scoreText = FormatWithLeadingZeros(game.score, 5);
		DrawText(scoreText.c_str(), 50, 40, 33, YELLOW);
		DrawText("High Score: ", 570, 15, 33, YELLOW);
		std::string highScoreText = FormatWithLeadingZeros(game.highScore, 5);
		DrawText(highScoreText.c_str(), 655, 40, 33, YELLOW);
		
		game.Draw();
		EndDrawing();
	}
	CloseAudioDevice();
	CloseWindow();
}