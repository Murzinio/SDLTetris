#pragma once
#include "VisibleEntity.h"

class VisibleEntity;

class Board : 
	public VisibleEntity
{
private:
	SDL_Texture* texture = textures.GameBoard.GetSDLTexture();
	SDL_Rect dstRect{0, 0, GLOBAL_gameBoardWidth, GLOBAL_gameBoardHeight};

public:
	Board();
	~Board();

	void Draw();
};

