#pragma once
#include <vector>

#include "VisibleEntity.h"

class VisibleEntity;

enum class ETetrominoType;
struct TetrominoPosition;

class Tetromino 
	: public VisibleEntity
{
private:
	ETetrominoType type;

	static SDL_Texture* textureO;

	SDL_Rect dstRect;

	void FillTextures();
	
public:
	
	Tetromino(ETetrominoType t);
	~Tetromino();

	SDL_Rect GetDstRect();
	void SetDstRect(SDL_Rect* rect);

	void Draw();

	int GetTetrominoSize();
	
};

