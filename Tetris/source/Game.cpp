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

	currentTetromino = new Tetromino(ETetrominoType::TYPE_O);
	allTetrominos.push_back(currentTetromino);
	while (!menuRequested && !gameOver)
	{
		menuRequested = inputHandler.GetMenuRequested();
		inputHandler.HandleEvents();
		renderer.Clear();

		texture = textures.background_Sunset.GetSDLTexture();
		renderer.AddToQueue(texture, NULL, NULL);

		gameBoard.Draw();
		

		if (GetTimeFromLastUpdate() >= gameplayInterval)
		{
			if (!currentTetromino->HasReachedBottom()
				&& IsPositionFree({ currentTetromino->GetDstRect().x, currentTetromino->GetDstRect().y + currentTetromino->GetTetrominoSize() }))
				UpdateCurrentTetrominoPosition();
			else if (currentTetromino->GetDstRect().y == currentTetromino->GetTetrominoSize())
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
		if (!mainMenu.GetExit())
			ResumeGameplayLoop();
	}
}

Tetromino* Game::CreateNewTetromino()
{
	return new Tetromino(ETetrominoType::TYPE_O);
}

void Game::DrawPlacedTetrominos()
{
	for (auto & x : placedTetrominos)
		x->Draw();
}

void Game::UpdateCurrentTetrominoPosition()
{
	SDL_Rect dstRect = currentTetromino->GetDstRect();
	
	dstRect.y += currentTetromino->GetTetrominoSize();
	if (IsPositionFree({ dstRect.x, currentTetromino->GetDstRect().y }));
		currentTetromino->SetDstRect(&dstRect);
}

bool Game::IsPositionFree(TetrominoPosition pos)
{
	for (auto & usedPos: tetrominoPositions)
		if (usedPos.y == pos.y)
			return false;
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
