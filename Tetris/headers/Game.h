#pragma once
#include <vector>
#include <chrono>
#include <stdlib.h> 

#include "Renderer.h"
#include "InputHandler.h"

#include "Menu.h"
#include "Tetromino.h"
#include "PhantomTetromino.h"
#include "Board.h"


enum class EScreenPosition;
enum class ETetrominoType;
struct TetrominoTexture;

class Logger;
class InputHandler;
class Menu;
class Tetromino;
class PhantomTetromino;
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

	std::vector<std::shared_ptr<Tetromino>> allTetrominos;
	std::vector<std::shared_ptr<Tetromino>> placedTetrominos;
	std::shared_ptr<Tetromino> currentTetromino;

	std::shared_ptr<PhantomTetromino> phantom;

	int framesCounter{ 0 };
	int counter;
	
	void StartGameplayLoop(bool resume);
	int previousRandom{ 0 };
	bool HandleMoves();
	void MoveTetrominoDown();

	std::shared_ptr<Tetromino> CreateNewTetromino();
	void DrawPlacedTetrominos();
	bool IsPositionFreePhantom();
	bool IsPositionFree();
	bool IsPositionFree(ETetrominoMove move);
	
	bool IsLastRowFilled();
	void DestroyLastRowBlocks();
	void MovePlacedTetrominosDown();
public:
	Game();
	~Game();
	void ExitRequested();
};

