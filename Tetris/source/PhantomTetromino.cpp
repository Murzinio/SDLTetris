#include "..\headers\PhantomTetromino.h"


PhantomTetromino::PhantomTetromino(ETetrominoType t)
{
	type = t;
	CreateBlocks();
}


PhantomTetromino::~PhantomTetromino()
{
}

void PhantomTetromino::CreateBlocks()
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
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		}
		break;
	case ETetrominoType::O:
		for (int i = 0; i < 2; ++i)
		{
			dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
			dstRect.y = GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		}
		for (int i = 0; i < 2; ++i)
		{
			dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
			dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		}
		break;
	case ETetrominoType::T:
		for (int i = 0; i < 3; ++i)
		{
			dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
			dstRect.y = GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		}
		dstRect.x = GLOBAL_gameBoardWidth / 2;
		dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
		blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		break;
	case ETetrominoType::J:
		for (int i = 0; i < 3; ++i)
		{
			dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
			dstRect.y = GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		}
		dstRect.x = GLOBAL_gameBoardWidth / 2 + GLOBAL_tetrominoBlockSize;
		dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
		blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		break;
	case ETetrominoType::L:
		for (int i = 0; i < 3; ++i)
		{
			dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
			dstRect.y = GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		}
		dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize;
		dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
		blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		break;
	case ETetrominoType::S:
		for (int i = 1; i < 3; ++i)
		{
			dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
			dstRect.y = GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		}
		for (int i = 0; i < 2; ++i)
		{
			dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
			dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		}
		break;
	case ETetrominoType::Z:
		for (int i = 0; i < 2; ++i)
		{
			dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
			dstRect.y = GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		}
		for (int i = 1; i < 3; ++i)
		{
			dstRect.x = GLOBAL_gameBoardWidth / 2 - GLOBAL_tetrominoBlockSize + (i * GLOBAL_tetrominoBlockSize);
			dstRect.y = 2 * GLOBAL_tetrominoBlockSize;
			blocks.push_back(std::make_shared<TetrominoBlock>(ETetrominoBlockColor::PHANTOM, dstRect));
		}
		break;
	}
	for (auto & x : blocks)
		x->ChangePosition(EPositionAxis::Y, GLOBAL_tetrominoBlockSize);
}