#include "..\headers\Tetromino.h"

Tetromino::Tetromino()
{
	srand(time(NULL));
}

Tetromino::Tetromino(ETetrominoType t)
{
	type = t;
	
	CreateBlocks();
	srand(time(NULL));
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
				blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
				blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize);

				blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -2);
				blocks[2]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 2);

				blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -3);
				blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 3);
				break;
			case 2:
				blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
				blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);

				blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -2);
				blocks[2]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -2);

				blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -3);
				blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -3);
				break;
			case 3:
				blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
				blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);

				blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 2);
				blocks[2]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -2);

				blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 3);
				blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -3);
				break;
			case 0:
				blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
				blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize);

				blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 2);
				blocks[2]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 2);

				blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 3);
				blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 3);
				break;
			}
			break;
		case ETetrominoType::T:
			switch (currentRotationVariant)
			{
				case 1:
					blocks[0]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);

					blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);

					blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					break;
				case 2:
					blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);
					break;
				case 3:
					blocks[0]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					blocks[0]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize);
					break;
				case 0:
					blocks[0]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
					blocks[0]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);
					
					blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize);

					blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);

					blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
					blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize);

					for (auto & x : blocks)
						x->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
					break;
			}
			break;
		case ETetrominoType::J:
			switch (currentRotationVariant)
			{
			case 1:
				blocks[0]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 2);
				blocks[0]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -2);

				blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
				blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);

				blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
				blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);
				break;
			case 2:
				blocks[0]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 2);
				blocks[0]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 2);

				blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
				blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize);

				blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 1);
				blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);
				break;
			case 3:
				blocks[0]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
				blocks[0]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -2);

				blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
				blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -2);
				break;
			case 0:
				blocks[0]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -2);
				blocks[0]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 2);

				blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 2);

				blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);

				blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
				blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 2);

				for (auto & x : blocks)
					x->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
				break;
				break;
			}
			break;
		case ETetrominoType::L:
			switch (currentRotationVariant)
			{
				case 1:
					blocks[0]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					blocks[0]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);

					blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);

					blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 2);
					break;
				case 2:
					blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					blocks[2]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);

					blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -3);

					for (auto & x : blocks)
						x->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
					break;
				case 3:
					blocks[0]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 3);

					blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -2);

					for (auto & x : blocks)
						x->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
					break;
				case 0:
					blocks[1]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 2);
					blocks[1]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 2);

					blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * 3);

					blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 2);

					for (auto & x : blocks)
						x->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -2);
					break;
			}
			break;
		case ETetrominoType::S:
			switch (currentRotationVariant)
			{
				case 1:
				case 3:
					blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					blocks[2]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -2);

					blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
					break;
				case 2:
				case 0:
					blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
					blocks[2]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 2);

					blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
					break;
			}
			break;
		case ETetrominoType::Z:
			switch (currentRotationVariant)
			{
			case 1:
			case 3:
				blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);

				blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
				blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -2);
				break;
			case 2:
			case 0:
				blocks[2]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);

				blocks[3]->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
				blocks[3]->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * 2);
				break;
			}
			break;
	}
	if (type != ETetrominoType::O)
	{
		for (auto & x : blocks)
			if (HasReachedBoundary(ETetrominoMove::LEFT))
				for (auto & y : blocks)
					y->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
			else if (HasReachedBoundary(ETetrominoMove::RIGHT))
				for (auto & y : blocks)
					y->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
			else if (HasReachedBottom())
				for (auto & y : blocks)
					y->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);
	}
	
}

void Tetromino::CreateBlocks()
{
	SDL_Rect dstRect{ 0, 0, GLOBAL_tetrominoBlockSize , GLOBAL_tetrominoBlockSize };

	int colorsCount{ (int)ETetrominoBlockColor::COUNT };
	int random{ rand() % colorsCount };

	switch (type)
	{	
		case ETetrominoType::I:
			for (int i = 0; i < 4; ++i)
			{
				dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
				dstRect.y = GLOBAL_tetrominoBlockSize;
				blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			}
			break;
		case ETetrominoType::O:
			for (int i = 0; i < 2; ++i)
			{
				dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
				dstRect.y = GLOBAL_tetrominoBlockSize;
				blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			}
			for (int i = 0; i < 2; ++i)
			{
				dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
				dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
				blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			}
			break;
		case ETetrominoType::T:
			for (int i = 0; i < 3; ++i)
			{
				dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
				dstRect.y = GLOBAL_tetrominoBlockSize;
				blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			}
			dstRect.x = GLOBAL_gameBoardWidth / 2;
			dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			break;
		case ETetrominoType::J:
			for (int i = 0; i < 3; ++i)
			{
				dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
				dstRect.y = GLOBAL_tetrominoBlockSize;
				blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			}
			dstRect.x = GLOBAL_gameBoardWidth / 2 + GLOBAL_tetrominoBlockSize;
			dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			break;
		case ETetrominoType::L:
			for (int i = 0; i < 3; ++i)
			{
				dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
				dstRect.y = GLOBAL_tetrominoBlockSize;
				blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			}
			dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize;
			dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			break;
		case ETetrominoType::S:
			for (int i = 1; i < 3; ++i)
			{
				dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
				dstRect.y = GLOBAL_tetrominoBlockSize;
				blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			}
			for (int i = 0; i < 2; ++i)
			{
				dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
				dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
				blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			}
			break;
		case ETetrominoType::Z:
			for (int i = 0; i < 2; ++i)
			{
				dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
				dstRect.y = GLOBAL_tetrominoBlockSize;
				blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
			}
			for (int i = 1; i < 3; ++i)
			{
				dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
				dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
				blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor(random), dstRect));
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
		if (x.y + 2 * GLOBAL_tetrominoBlockSize >= GLOBAL_gameBoardHeight)
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
				if (x.x + 2 * GLOBAL_tetrominoBlockSize >= GLOBAL_gameBoardWidth)
					return true;
			break;
		case ETetrominoMove::LEFT:
			for (auto & x : positions)
				if (x.x - GLOBAL_tetrominoBlockSize < GLOBAL_tetrominoBlockSize)
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
		for (auto & block : blocks)
			block->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize);
		break;
	case ETetrominoMove::LEFT:
		for (auto & block : blocks)
			block->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize * -1);
		break;
	case ETetrominoMove::RIGHT:
		for (auto & block : blocks)
			block->ChangePosition(EPositionAxis::X, GLOBAL_tetrominoBlockSize);
		break;
	case ETetrominoMove::UP:
		for (auto & block : blocks)
			block->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize * -1);
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

std::shared_ptr<TetrominoBlock> Tetromino::GetBlockById(int id)
{
	return blocks[id];
}

void Tetromino::DestroyBlockById(int id)
{
 	blocks[id].reset();
   	blocks.erase(blocks.begin() + id);
}