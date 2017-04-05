#include "..\headers\Tetromino.h"

SDL_Texture* Tetromino::textureO;

int Tetromino::tetrominoSize;

Tetromino::Tetromino(ETetrominoType t)
{
	type = t;
	tetrominoSize = SCREEN_WIDTH / 30;
	dstRect.w = dstRect.h = tetrominoSize;
	dstRect.x = gameBoardWidth / 2 - (dstRect.w / 2);
	dstRect.y = 64;
}


Tetromino::~Tetromino()
{
}

/*
	Private
*/

void Tetromino::Draw()
{
	SDL_Texture* texture{ NULL };
	switch (type)
	{
		case ETetrominoType::TYPE_O:
			texture = textures.Tetromino_O.GetSDLTexture();
			break;
	}
	
	

	renderer->AddToQueue(texture, NULL, &dstRect);
}

/*
	Public
*/

SDL_Rect Tetromino::GetDstRect()
{
	return dstRect;
}

void Tetromino::SetDstRect(SDL_Rect* rect)
{
	dstRect = *rect;
}



bool Tetromino::HasReachedBottom()
{
	if (dstRect.y  > gameBoardHeight - 2 * tetrominoSize)
		return true;
	return false;
}

bool Tetromino::HasReachedBoundary(EBoardBoundary boundary)
{
	switch (boundary)
	{
		case EBoardBoundary::RIGHT:
			if (dstRect.x < gameBoardWidth - 2 * tetrominoSize)
				return false;
			break;
		case EBoardBoundary::LEFT:
			if (dstRect.x > tetrominoSize)
				return false;
			break;
	}
	
	return true;
}