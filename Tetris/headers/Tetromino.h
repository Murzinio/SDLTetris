#pragma once
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
	std::vector<TetrominoBlock*> blocks;

	ETetrominoType type;

	static SDL_Texture* textureO;

	SDL_Rect dstRect;

	bool isAtTop{ true };

	void CreateBlocks();

public:
	
	Tetromino(ETetrominoType t);
	~Tetromino();

	SDL_Rect GetDstRect();
	void SetDstRect(SDL_Rect* rect);

	void Draw();

	int GetTetrominoBlockSize();
	
	bool GetIsAtTop();
	bool HasReachedBottom();
	bool HasReachedBoundary(EBoardBoundary boundary);
	void Move(ETetrominoMove move);

	std::vector<Position> GetBlocksPositions();
};

inline int Tetromino::GetTetrominoBlockSize()
{
	return tetrominoBlockSize;
}

inline bool Tetromino::GetIsAtTop()
{
	return isAtTop;
}