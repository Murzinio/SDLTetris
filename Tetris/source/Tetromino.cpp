#include "..\headers\Tetromino.h"

SDL_Texture* Tetromino::textureO;

int Tetromino::tetrominoSize;

Tetromino::Tetromino(ETetrominoType t)
{
	type = t;
	tetrominoSize = SCREEN_WIDTH / 30;
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
	dstRect.w = dstRect.h = tetrominoSize;
	dstRect.x = gameBoardWidth / 2 - (dstRect.w / 2);

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

int Tetromino::GetTetrominoSize()
{
	return tetrominoSize;
}

bool Tetromino::HasReachedBottom()
{
	if (dstRect.y  > gameBoardHeight - 2 * tetrominoSize)
		return true;
	return false;
}

