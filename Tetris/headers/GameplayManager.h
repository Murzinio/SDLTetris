#pragma once
#include <chrono>

#include <vector>

#include "InputHandler.h"
#include "Tetromino.h"
#include "Renderer.h"

class GameplayManager
{
private:
	
	Tetromino* currentTetromino;



	float tetrominoSize{ 3.0 / 4.0 * (SCREEN_WIDTH - (SCREEN_WIDTH / 4.0)) / 20.0 };
	int tetrominoSizeInt{ (int)tetrominoSize };

	SDL_Rect dstRectTetromino{ 0, 0, 0, 0 };

	InputHandler* inputHandler;
	Renderer* renderer;


public:
	GameplayManager(InputHandler* ih, Renderer* r);
	~GameplayManager();

	std::vector<TetrominoPosition> UpdateGameplay(std::vector<TetrominoPosition> tetrominoPositions);
};

