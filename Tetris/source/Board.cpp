#include "..\headers\Board.h"



Board::Board()
{
	gameBoardWidth = dstRect.w;
}


Board::~Board()
{
}

void Board::Draw()
{
	
	texture = textures.GameBoard.GetSDLTexture();
	renderer->AddToQueue(texture, NULL, &dstRect);
}