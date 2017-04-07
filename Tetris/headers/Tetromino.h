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
private:
	std::vector<std::shared_ptr<TetrominoBlock>> blocks;

	ETetrominoType type;

	static SDL_Texture* textureO;

	SDL_Rect dstRect;

	bool isAtTop{ true };
	int currentRotationVariant{ 0 };
	void CreateBlocks();

public:
	
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
};

inline bool Tetromino::GetIsAtTop()
{
	return isAtTop;
}