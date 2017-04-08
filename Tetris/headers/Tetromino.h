#pragma once

#include <stdlib.h>
#include <chrono>
#include <vector>

#include "VisibleEntity.h"
#include "TetrominoBlock.h"

class VisibleEntity;

enum class ETetrominoType;
struct TetrominoPosition;

class Tetromino 
	: public VisibleEntity
{
protected:
	std::vector<std::shared_ptr<TetrominoBlock>> blocks;

	ETetrominoType type;

	SDL_Rect dstRect;

	bool isAtTop{ true };
	int currentRotationVariant{ 0 };
	void CreateBlocks();

public:
	
	Tetromino();
	Tetromino(ETetrominoType t);
	~Tetromino();

	SDL_Rect GetDstRect();
	void SetDstRect(SDL_Rect* rect);

	void Draw();
	
	bool GetIsAtTop();
	bool HasReachedBottom();
	bool HasReachedBoundary(ETetrominoMove move);
	void Move(ETetrominoMove move);
	void Rotate();

	std::vector<Position> GetBlocksPositions();
	ETetrominoType GetType();

	std::shared_ptr<TetrominoBlock> GetBlockById(int id);
	void DestroyBlockById(int id);
};

inline bool Tetromino::GetIsAtTop()
{
	return isAtTop;
}

inline ETetrominoType Tetromino::GetType()
{
	return type;
}