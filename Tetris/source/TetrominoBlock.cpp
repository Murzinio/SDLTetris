#include "..\headers\TetrominoBlock.h"



TetrominoBlock::TetrominoBlock(ETetrominoBlockColor c, SDL_Rect &dstr)
{
	color = c;
	dstRect = dstr;
	switch (color)
	{
		case ETetrominoBlockColor::YELLOW:
			texture = textures.TetrominoBlock_Yellow.GetSDLTexture();
			break;
		case ETetrominoBlockColor::TURQUOISE:
			texture = textures.TetrominoBlock_Turquoise.GetSDLTexture();
			break;
		case ETetrominoBlockColor::PURPLE:
			texture = textures.TetrominoBlock_Purple.GetSDLTexture();
			break;
		case ETetrominoBlockColor::BLUE:
			texture = textures.TetrominoBlock_Blue.GetSDLTexture();
			break;
	}
}


TetrominoBlock::~TetrominoBlock()
{
}

void TetrominoBlock::Draw()
{
	renderer->AddToQueue(texture, NULL, &dstRect);
}

void TetrominoBlock::ChangePosition(EPositionAxis axis, int offset)
{
	switch (axis)
	{
		case EPositionAxis::X:
			dstRect.x += offset;
			break;
		case EPositionAxis::Y:
			dstRect.y += offset;
			break;
	}
}