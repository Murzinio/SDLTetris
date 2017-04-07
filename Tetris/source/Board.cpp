#include "..\headers\Board.h"



Board::Board()
{
}


Board::~Board()
{
}

void Board::Draw()
{
	
	texture = textures.GameBoard.GetSDLTexture();
	renderer->AddToQueue(texture, NULL, &dstRect);
}