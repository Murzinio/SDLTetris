#include "..\headers\GameplayManager.h"



GameplayManager::GameplayManager(InputHandler* ih, Renderer* r)
{
	inputHandler = ih;
	renderer = r;
}


GameplayManager::~GameplayManager()
{

}

/* 
	Private 
*/

/*
	Public
*/

//std::vector<TetrominoPosition> GameplayManager::UpdateGameplay(TetrominoPosition tetrominoPosition)
//{
//	std::vector<TetrominoPosition> updatedTetrominoPositions = tetrominoPositions;
//
//	return updatedTetrominoPositions;
//}
