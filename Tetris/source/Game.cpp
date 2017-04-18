#include "..\headers\Game.h"

Game::Game() : dummyEntity(), mainMenu(EMenuType::MAIN_MENU), resumeMenu(EMenuType::RESUME_MENU)
{
	dummyEntity.PassRenderer(&renderer);

	if (dummyEntity.LoadTextures())
	{
		textures = dummyEntity.GetTextures();
		logger.Log("Textures loaded.");
	}
		
	else
		logger.LogError("Failed to load textures.");

	logger.Log("Game initialised.");

	mainMenu.CreateButtons();
	resumeMenu.CreateButtons();
	mainMenu.StartLoop();

	if (!mainMenu.GetExit())
		GameplayLoop(false);

	srand(time(NULL));
}

Game::~Game()
{
	logger.Log("Exitting...");

	SDL_Quit();
}

/*
--------- Private ---------
*/


void Game::GameplayLoop(bool resume)
{
	previous_update = std::chrono::high_resolution_clock::now();

	SDL_Texture* backgroundTexture{ NULL };
	backgroundTexture = textures.background_Water.GetSDLTexture();
	bool menuRequested{ false };
	bool gameOver{ false };

	if (!resume)
	{
		currentTetromino = CreateNewTetromino();
		allTetrominos.push_back(currentTetromino);

		phantom = std::make_shared<PhantomTetromino>(currentTetromino->GetType());
	}

	while (!menuRequested && !gameOver)
	{
		menuRequested = inputHandler.GetMenuRequested();
		inputHandler.HandleEvents();
		renderer.Clear();

		renderer.AddToQueue(backgroundTexture, NULL, NULL);

		gameBoard.Draw();

		if (inputHandler.GetMoveRequested())
		{
			if (!HandleMoves())
			{
				if (currentTetromino->GetIsAtTop() && !IsPositionFree(ETetrominoMove::DOWN))
					gameOver = true;
				else
				{
					tetrominoPositions.push_back({ currentTetromino->GetDstRect().x, currentTetromino->GetDstRect().y });
					placedTetrominos.push_back(currentTetromino);
					currentTetromino = CreateNewTetromino();
					if (IsLastRowFilled())
					{
						DestroyLastRowBlocks();
						MovePlacedTetrominosDown();
						if (IsLastRowFilled())
						{
							DestroyLastRowBlocks();
							MovePlacedTetrominosDown();
						}
					}
					phantom = std::make_shared<PhantomTetromino>(currentTetromino->GetType());
				}
			}
		}
			
		else if (inputHandler.GetFastPlacementRequested())
		{
			while (!currentTetromino->HasReachedBottom() && IsPositionFree(ETetrominoMove::DOWN))
				currentTetromino->Move(ETetrominoMove::DOWN);
			tetrominoPositions.push_back({ currentTetromino->GetDstRect().x, currentTetromino->GetDstRect().y });
			placedTetrominos.push_back(currentTetromino);
			currentTetromino = CreateNewTetromino();
			if (IsLastRowFilled())
			{
				DestroyLastRowBlocks();
				MovePlacedTetrominosDown();
				if (IsLastRowFilled())
				{
					DestroyLastRowBlocks();
					MovePlacedTetrominosDown();
				}
					
			}
			phantom = std::make_shared<PhantomTetromino>(currentTetromino->GetType());
		}

		if (GetTimeFromLastUpdate() >= gameplayInterval)
		{
			if (!currentTetromino->HasReachedBottom() && IsPositionFree(ETetrominoMove::DOWN))
			{
				currentTetromino->Move(ETetrominoMove::DOWN);
			}

			else if (currentTetromino->GetIsAtTop() && !IsPositionFree(ETetrominoMove::DOWN))
				gameOver = true;
			else
			{
				
				tetrominoPositions.push_back({ currentTetromino->GetDstRect().x, currentTetromino->GetDstRect().y });
				placedTetrominos.push_back(currentTetromino);
				currentTetromino = CreateNewTetromino();
				if (IsLastRowFilled())
				{
					DestroyLastRowBlocks();
					MovePlacedTetrominosDown();
					if (IsLastRowFilled())
					{
						DestroyLastRowBlocks();
						MovePlacedTetrominosDown();
					}
				}
				phantom = std::make_shared<PhantomTetromino>(currentTetromino->GetType());
			}

			previous_update = std::chrono::high_resolution_clock::now();
		}

		DrawPlacedTetrominos();


		while (!phantom->HasReachedBottom() && IsPositionFreePhantom())
			phantom->Move(ETetrominoMove::DOWN);
		while (!IsPositionFreePhantom())
			phantom->Move(ETetrominoMove::UP);

		phantom->Draw();
		currentTetromino->Draw();

		renderer.Render();
	}
	if (menuRequested)
	{
		resumeMenu.StartLoop();
		if (!resumeMenu.GetExit())
			GameplayLoop(true);
	}
}

bool Game::HandleMoves()
{
	ETetrominoMove move{ inputHandler.GetMove() };

	if (move == ETetrominoMove::DOWN && (currentTetromino->HasReachedBottom() || !IsPositionFree(move)))
		return false;
	else if (move == ETetrominoMove::ROTATE)
	{
		currentTetromino->Rotate();
		phantom->Rotate();
		while (!IsPositionFreePhantom())
			phantom->Move(ETetrominoMove::UP);
		while (!IsPositionFree())
			currentTetromino->Move(ETetrominoMove::UP);
			
	}	
	else if (IsPositionFree(move) && !currentTetromino->HasReachedBoundary(move))
	{
		currentTetromino->Move(move);
		if (move != ETetrominoMove::DOWN)
			phantom->Move(move);
		while (!IsPositionFreePhantom())
			phantom->Move(ETetrominoMove::UP);
	}
		
	
	return true;
}

std::shared_ptr<Tetromino> Game::CreateNewTetromino()
{
	int typesCount{ (int)ETetrominoType::COUNT };
	int random{ rand() % typesCount };
	while (random == previousRandom)
	{
		random = rand() % typesCount + 0;
	}
	previousRandom = random;
	return std::make_shared<Tetromino>((ETetrominoType)random);
}

void Game::DrawPlacedTetrominos()
{
	for (auto & x : placedTetrominos)
		x->Draw();
}

void Game::MoveTetrominoDown()
{
	SDL_Rect dstRect = currentTetromino->GetDstRect();
	dstRect.y += GLOBAL_tetrominoBlockSize;

	currentTetromino->SetDstRect(&dstRect);
}

bool Game::IsPositionFree()
{
	std::vector<Position> placedBlocksPositions;

	for (auto & x : placedTetrominos)
	{
		std::vector<Position> blocksPositions{ x->GetBlocksPositions() };
		for (auto & y : blocksPositions)
			placedBlocksPositions.push_back(y);
	}

	int tetrominoBlockSize{ GLOBAL_tetrominoBlockSize };

	std::vector<Position> currentBlocksPositions{ currentTetromino->GetBlocksPositions() };
		for (auto & currentPos : currentBlocksPositions)
			for (auto & placedPos : placedBlocksPositions)
				if (currentPos.x == placedPos.x && currentPos.y == placedPos.y)
					return false;

	return true;
}

bool Game::IsPositionFreePhantom()
{
	std::vector<Position> placedBlocksPositions;

	for (auto & x : placedTetrominos)
	{
		std::vector<Position> blocksPositions{ x->GetBlocksPositions() };
		for (auto & y : blocksPositions)
			placedBlocksPositions.push_back(y);
	}

	int tetrominoBlockSize{ GLOBAL_tetrominoBlockSize };

	std::vector<Position> currentBlocksPositions{ phantom->GetBlocksPositions() };
	for (auto & currentPos : currentBlocksPositions)
		for (auto & placedPos : placedBlocksPositions)
			if (currentPos.x == placedPos.x && currentPos.y == placedPos.y)
				return false;
	for (auto & currentPos : currentBlocksPositions)
		for (auto & placedPos : placedBlocksPositions)
			if (currentPos.x == placedPos.x && currentPos.y > placedPos.y)
				return false;

	return true;
}

bool Game::IsPositionFree(ETetrominoMove move)
{
	std::vector<Position> placedBlocksPositions;
	
	for (auto & x : placedTetrominos)
	{
		std::vector<Position> blocksPositions{ x->GetBlocksPositions() };
		for (auto & y : blocksPositions)
			placedBlocksPositions.push_back(y);
	}

	int tetrominoBlockSize{ GLOBAL_tetrominoBlockSize };

	std::vector<Position> currentBlocksPositions{ currentTetromino->GetBlocksPositions() };
	switch (move)
	{
		case ETetrominoMove::DOWN:
			for (auto & currentPos : currentBlocksPositions)
				for (auto & placedPos : placedBlocksPositions)
					if (currentPos.x == placedPos.x && currentPos.y + tetrominoBlockSize == placedPos.y)
						return false;
			break;
		case ETetrominoMove::LEFT:
			for (auto & currentPos : currentBlocksPositions)
				for (auto & placedPos : placedBlocksPositions)
					if (currentPos.x - tetrominoBlockSize == placedPos.x && currentPos.y == placedPos.y)
						return false;
			break;
		case ETetrominoMove::RIGHT:
			for (auto & currentPos : currentBlocksPositions)
				for (auto & placedPos : placedBlocksPositions)
					if (currentPos.x + tetrominoBlockSize == placedPos.x && currentPos.y == placedPos.y)
						return false;
			break;
	}

	return true;
}

int Game::GetTimeFromLastUpdate()
{
	std::chrono::high_resolution_clock::time_point currentUpdate{ std::chrono::high_resolution_clock::now() };
	int lastUpdateDelta = std::chrono::duration_cast<std::chrono::milliseconds>(currentUpdate - previous_update).count();
	return lastUpdateDelta;
}

bool Game::IsLastRowFilled()
{
	int lastRowBlocksCount{ 0 };

	for (auto & tetromino : placedTetrominos)
	{
		std::vector<Position> blocksPositions{ tetromino->GetBlocksPositions() };
		int blocksPositionsSize{ (int)blocksPositions.size() };
		for (int i = 0; i < blocksPositionsSize; ++i)
			if (blocksPositions[i].y + 2 * GLOBAL_tetrominoBlockSize >= GLOBAL_gameBoardHeight)
				++lastRowBlocksCount;
			else if (blocksPositions[i].y + 3 * GLOBAL_tetrominoBlockSize < GLOBAL_gameBoardHeight)
				break; // no need to check all blocks if any of them is too far from bottom
	}
	if (lastRowBlocksCount == GLOBAL_gameBoardWidth / GLOBAL_tetrominoBlockSize - 2)
		return true;

	return false;
}

void Game::DestroyLastRowBlocks()
{
	for (auto & tetromino : placedTetrominos)
	{
		std::vector<Position> blocksPositions{ tetromino->GetBlocksPositions() };
		int blocksPositionsSize{ (int)blocksPositions.size() };
		for (int i = 0; i < blocksPositionsSize; ++i)
			if (blocksPositions[i].y + 2 * GLOBAL_tetrominoBlockSize >= GLOBAL_gameBoardHeight)
			{
 				tetromino->DestroyBlockById(i);
				blocksPositions.erase(blocksPositions.begin() + i);
				i--;
			}			
	}
}

void Game::MovePlacedTetrominosDown()
{
	for (auto & tetromino : placedTetrominos)
	{
		tetromino->Move(ETetrominoMove::DOWN);
	}
}

/*
--------- Public ---------
*/

void Game::ExitRequested()
{
	logger.Log("Exit requested.");
	exit = true;
}
