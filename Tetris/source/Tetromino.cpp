#include "..\headers\Tetromino.h"

SDL_Texture* Tetromino::textureO;


Tetromino::Tetromino(ETetrominoType t)
{
	type = t;
	
	tetrominoBlockSize = SCREEN_WIDTH / 60;
	CreateBlocks();
}


Tetromino::~Tetromino()
{
}

/*
	Private
*/

void Tetromino::Draw()
{
	for (auto x : blocks)
		x->Draw();
}

void Tetromino::CreateBlocks()
{
	SDL_Rect dstRect{ 0, 0, tetrominoBlockSize , tetrominoBlockSize };
	switch (type)
	{	
		case ETetrominoType::I:
			for (int i = 0; i < 4; ++i)
			{
				dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize + (i * tetrominoBlockSize);
				dstRect.y = tetrominoBlockSize;
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::TURQUOISE, dstRect));
			}
			break;
		case ETetrominoType::O:
			for (int i = 0; i < 2; ++i)
			{
				dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize + (i * tetrominoBlockSize);
				dstRect.y = tetrominoBlockSize;
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::YELLOW, dstRect));
			}
			for (int i = 0; i < 2; ++i)
			{
				dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize + (i * tetrominoBlockSize);
				dstRect.y = 2 * tetrominoBlockSize;
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::YELLOW, dstRect));
			}
			break;
		case ETetrominoType::T:
			for (int i = 0; i < 3; ++i)
			{
				dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize + (i * tetrominoBlockSize);
				dstRect.y = tetrominoBlockSize;
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::PURPLE, dstRect));
			}
			dstRect.x = gameBoardWidth / 2;
			dstRect.y = 2 * tetrominoBlockSize;
			blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::PURPLE, dstRect));
			break;
		case ETetrominoType::J:
			for (int i = 0; i < 3; ++i)
			{
				dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize + (i * tetrominoBlockSize);
				dstRect.y = tetrominoBlockSize;
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::BLUE, dstRect));
			}
			dstRect.x = gameBoardWidth / 2 + tetrominoBlockSize;
			dstRect.y = 2 * tetrominoBlockSize;
			blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::BLUE, dstRect));
			break;
		case ETetrominoType::L:
			for (int i = 0; i < 3; ++i)
			{
				dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize + (i * tetrominoBlockSize);
				dstRect.y = tetrominoBlockSize;
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::BLUE, dstRect));
			}
			dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize;
			dstRect.y = 2 * tetrominoBlockSize;
			blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::BLUE, dstRect));
			break;
	}
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
	std::vector<Position> positions{ GetBlocksPositions() };

	for (auto & x : positions)
	{
		if (x.y + 2 * tetrominoBlockSize >= gameBoardHeight)
			return true;
	}
	return false;
}

bool Tetromino::HasReachedBoundary(EBoardBoundary boundary)
{
	switch (boundary)
	{
		case EBoardBoundary::RIGHT:
			if (dstRect.x < gameBoardWidth - 2 * tetrominoBlockSize)
				return false;
			break;
		case EBoardBoundary::LEFT:
			if (dstRect.x > tetrominoBlockSize)
				return false;
			break;
	}
	
	return true;
}

void Tetromino::Move(ETetrominoMove move)
{
	//SDL_Rect rect;

	switch (move)
	{
	case ETetrominoMove::DOWN:
		if (isAtTop)
			isAtTop = false;
		for (int i = 0; i < 4; ++i)
			blocks[i]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize);
		break;
	case ETetrominoMove::LEFT:
		for (int i = 0; i < 4; ++i)
			blocks[i]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -1);
		break;
	case ETetrominoMove::RIGHT:
		for (int i = 0; i < 4; ++i)
			blocks[i]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);
		break;
	}

	//dstRect = rect;

}

std::vector<Position> Tetromino::GetBlocksPositions()
{
	std::vector<Position> positions;

	for (auto & x : blocks)
		positions.push_back(x->GetPosition());

	return positions;
}