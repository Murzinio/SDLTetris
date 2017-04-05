#pragma once

#include "VisibleEntity.h"

class TetrominoBlock 
	: public VisibleEntity
{
private:
	ETetrominoBlockColor color;
	SDL_Rect dstRect;

	SDL_Texture* texture;
public:
	TetrominoBlock(ETetrominoBlockColor c, SDL_Rect &dstr);
	~TetrominoBlock();

	Position GetPosition();
	void ChangePosition(EPositionAxis axis, int offset);

	void Draw();
};

inline Position TetrominoBlock::GetPosition()
{
	return { dstRect.x, dstRect.y };
}