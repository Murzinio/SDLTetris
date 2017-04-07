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
		StartGameplayLoop();

	srand(time(NULL));
}

Game::~Game()
{
	logger.Log("Exitting...");

	for (auto & x : allTetrominos)
		delete x;

	SDL_Quit();
}

/*
--------- Private ---------
*/


void Game::StartGameplayLoop()
{
	previous_update = std::chrono::high_resolution_clock::now();

	SDL_Texture* texture{ NULL };
	bool menuRequested{ false };
	bool gameOver{ false };

	currentTetromino = CreateNewTetromino();
	allTetrominos.push_back(currentTetromino);

	while (!menuRequested && !gameOver)
	{
		menuRequested = inputHandler.GetMenuRequested();
		inputHandler.HandleEvents();
		renderer.Clear();

		texture = textures.background_Sunset.GetSDLTexture();
		renderer.AddToQueue(texture, NULL, NULL);

		gameBoard.Draw();
		
		if (inputHandler.GetMoveRequested())
			if (!HandleMoves())
			{
				if (currentTetromino->GetIsAtTop() && !IsPositionFree(ETetrominoMove::DOWN))
					gameOver = true;
				else
				{
					tetrominoPositions.push_back({ currentTetromino->GetDstRect().x, currentTetromino->GetDstRect().y });
					placedTetrominos.push_back(currentTetromino);
					currentTetromino = CreateNewTetromino();
				}
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
			}

			previous_update = std::chrono::high_resolution_clock::now();
		}

		DrawPlacedTetrominos();

		currentTetromino->Draw();
		renderer.Render();
	}
	if (menuRequested)
	{
		
		resumeMenu.StartLoop();
		if (!resumeMenu.GetExit())
			ResumeGameplayLoop();
	}
}

bool Game::HandleMoves()
{
	ETetrominoMove move{ inputHandler.GetMove() };

	if (move == ETetrominoMove::DOWN && (currentTetromino->HasReachedBottom() || !IsPositionFree(move)))
		return false;
	else if (move == ETetrominoMove::ROTATE)
		currentTetromino->Rotate();
	else if (IsPositionFree(move) && !currentTetromino->HasReachedBoundary(move))
		currentTetromino->Move(move);
	
	return true;
}

Tetromino* Game::CreateNewTetromino()
{
	int typesCount{ (int)ETetrominoType::COUNT };
	int random{ rand() % typesCount + 0 };
	while (random == previousRandom)
	{
		random = rand() % typesCount + 0;
	}
	previousRandom = random;
	return new Tetromino((ETetrominoType)random);
	//return new Tetromino(ETetrominoType::J); 
	//for tests
}

void Game::DrawPlacedTetrominos()
{
	for (auto & x : placedTetrominos)
		x->Draw();
}

void Game::MoveTetrominoDown()
{
	SDL_Rect dstRect = currentTetromino->GetDstRect();
	dstRect.y += currentTetromino->GetTetrominoBlockSize();

	currentTetromino->SetDstRect(&dstRect);
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

	int tetrominoBlockSize{ currentTetromino->GetTetrominoBlockSize() };

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

void Game::ResumeGameplayLoop()
{
	SDL_Texture* texture{ NULL };
	bool menuRequested{ false };
	while (!menuRequested)
	{
		menuRequested = inputHandler.GetMenuRequested();
		inputHandler.HandleEvents();
		renderer.Clear();

		texture = textures.background_Sunset.GetSDLTexture();
		renderer.AddToQueue(texture, NULL, NULL);

		gameBoard.Draw();

		if (GetTimeFromLastUpdate() >= gameplayInterval)
		{
			previous_update = std::chrono::high_resolution_clock::now();
		}
		renderer.Render();
	}
	if (menuRequested)
	{
		mainMenu.StartLoop();
		if (!mainMenu.GetExit())
			ResumeGameplayLoop();
	}
}

int Game::GetTimeFromLastUpdate()
{
	std::chrono::high_resolution_clock::time_point currentUpdate{ std::chrono::high_resolution_clock::now() };
	int lastUpdateDelta = std::chrono::duration_cast<std::chrono::milliseconds>(currentUpdate - previous_update).count();
	return lastUpdateDelta;
}


/*
--------- Public ---------
*/

void Game::ExitRequested()
{
	logger.Log("Exit requested.");
	exit = true;
}
