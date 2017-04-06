#pragma once
#include <vector>
#include <chrono>
#include <stdlib.h> 

#include "Renderer.h"
#include "InputHandler.h"

#include "Menu.h"
#include "Tetromino.h"
#include "Board.h"


enum class EScreenPosition;
enum class ETetrominoType;
struct TetrominoTexture;

class Logger;
class InputHandler;
class Menu;
class Tetromino;
class GameplayManager;

class Game
{
private:
	Logger logger;
	InputHandler inputHandler;
	Renderer renderer;

	// to load textures and pass renderer
	Board dummyEntity; 
	Textures textures;

	std::vector<Position> tetrominoPositions;

	Board gameBoard;
	Menu mainMenu;
	Menu resumeMenu;

	SDL_Rect dstRect{ 0, 0, 0, 0 };
	
	bool exit;

	int gameplayInterval{ 1000 };
	std::chrono::high_resolution_clock::time_point previous_update{ std::chrono::high_resolution_clock::now() };
	int GetTimeFromLastUpdate();

	std::vector<Tetromino*> allTetrominos;
	std::vector<Tetromino*> placedTetrominos;
	Tetromino* currentTetromino;

	int framesCounter{ 0 };
	int counter;
	
	void StartGameplayLoop();
	bool HandleMoves();
	void MoveTetrominoDown();
	void ResumeGameplayLoop();

	Tetromino* CreateNewTetromino();
	void DrawPlacedTetrominos();
	bool IsPositionFree(ETetrominoMove move);
	

public:
	Game();
	~Game();
	void ExitRequested();
};

