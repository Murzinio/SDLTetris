#include "..\headers\Board.h"



Board::Board()
{
	gameBoardWidth = dstRect.w;
	gameBoardHeight = dstRect.h;
}


Board::~Board()
{
}

void Board::Draw()
{
	
	texture = textures.GameBoard.GetSDLTexture();
	renderer->AddToQueue(texture, NULL, &dstRect);
}