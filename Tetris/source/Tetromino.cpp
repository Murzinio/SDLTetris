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

void Tetromino::Rotate()
{
	if (currentRotationVariant < 3)
		++currentRotationVariant;
	else
		currentRotationVariant = 0;
	
	switch (type)
	{
		case ETetrominoType::I:
			switch (currentRotationVariant)
			{
			case 1:
				blocks[1]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -1);
				blocks[1]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize);

				blocks[2]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -2);
				blocks[2]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * 2);

				blocks[3]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -3);
				blocks[3]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * 3);
				break;
			case 2:
				blocks[1]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -1);
				blocks[1]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -1);

				blocks[2]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -2);
				blocks[2]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -2);

				blocks[3]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -3);
				blocks[3]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -3);
				break;
			case 3:
				blocks[1]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);
				blocks[1]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -1);

				blocks[2]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * 2);
				blocks[2]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -2);

				blocks[3]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * 3);
				blocks[3]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -3);
				break;
			case 0:
				blocks[1]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);
				blocks[1]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize);

				blocks[2]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * 2);
				blocks[2]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * 2);

				blocks[3]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * 3);
				blocks[3]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * 3);
				break;
			}
			break;
		case ETetrominoType::T:
			switch (currentRotationVariant)
			{
				case 1:
					blocks[0]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);

					blocks[1]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);
					blocks[1]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -1);

					blocks[3]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);
					break;
				case 2:
					blocks[3]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);
					blocks[3]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -1);
					break;
				case 3:
					blocks[0]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);
					blocks[0]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize);
					break;
				case 0:
					blocks[0]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -1);
					blocks[0]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -1);
					
					blocks[1]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize);

					blocks[2]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);

					blocks[3]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -1);
					blocks[3]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize);

					for (auto & x : blocks)
						x->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -1);
					break;
			}
			break;
		case ETetrominoType::J:
			switch (currentRotationVariant)
			{
			case 1:
				blocks[0]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * 2);
				blocks[0]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -2);

				blocks[1]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);
				blocks[1]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -1);

				blocks[3]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -1);
				blocks[3]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -1);
				break;
			case 2:
				blocks[0]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * 2);
				blocks[0]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * 2);

				blocks[1]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);
				blocks[1]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize);

				blocks[3]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * 1);
				blocks[3]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -1);
				break;
			case 3:
				blocks[0]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -1);
				blocks[0]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -2);

				blocks[1]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -1);
				blocks[1]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * -2);
				break;
			case 0:
				blocks[0]->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -2);
				blocks[0]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * 2);

				blocks[1]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * 2);

				blocks[2]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);

				blocks[3]->ChangePosition(EPositionAxis::X, tetrominoBlockSize);
				blocks[3]->ChangePosition(EPositionAxis::Y, tetrominoBlockSize * 2);

				for (auto & x : blocks)
					x->ChangePosition(EPositionAxis::X, tetrominoBlockSize * -1);
				break;
				break;
			}
			break;
	}
	
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
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::ORANGE, dstRect));
			}
			dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize;
			dstRect.y = 2 * tetrominoBlockSize;
			blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::ORANGE, dstRect));
			break;
		case ETetrominoType::S:
			for (int i = 1; i < 3; ++i)
			{
				dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize + (i * tetrominoBlockSize);
				dstRect.y = tetrominoBlockSize;
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::GREEN, dstRect));
			}
			for (int i = 0; i < 2; ++i)
			{
				dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize + (i * tetrominoBlockSize);
				dstRect.y = 2 * tetrominoBlockSize;
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::GREEN, dstRect));
			}
			break;
		case ETetrominoType::Z:
			for (int i = 0; i < 2; ++i)
			{
				dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize + (i * tetrominoBlockSize);
				dstRect.y = tetrominoBlockSize;
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::RED, dstRect));
			}
			for (int i = 1; i < 3; ++i)
			{
				dstRect.x = gameBoardWidth / 2 - tetrominoBlockSize + (i * tetrominoBlockSize);
				dstRect.y = 2 * tetrominoBlockSize;
				blocks.push_back(new TetrominoBlock(ETetrominoBlockColor::RED, dstRect));
			}
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

bool Tetromino::HasReachedBoundary(ETetrominoMove move)
{
	std::vector<Position> positions{ GetBlocksPositions() };

	switch (move)
	{	
		case ETetrominoMove::RIGHT:
			for (auto & x : positions)
				if (x.x + 2 * tetrominoBlockSize >= gameBoardWidth)
					return true;
			break;
		case ETetrominoMove::LEFT:
			for (auto & x : positions)
				if (x.x - tetrominoBlockSize < tetrominoBlockSize)
					return true;
			break;
	}
	
	return false;
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