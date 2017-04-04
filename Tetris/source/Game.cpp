#include "..\headers\Game.h"

Game::Game() : dummyEntity()
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

	CreateMainMenu();
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


void Game::CreateMainMenu()
{
	mainMenu.CreateButtons(EBoardType::MAIN_MENU);
	mainMenu.StartLoop();
}

void Game::StartGameplayLoop()
{
	previous_update = std::chrono::high_resolution_clock::now();

	SDL_Texture* texture{ NULL };
	bool menuRequested{ false };

	currentTetromino = new Tetromino(ETetrominoType::TYPE_O);
	allTetrominos.push_back(currentTetromino);
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
			UpdateCurrentTetrominoPosition();
			previous_update = std::chrono::high_resolution_clock::now();
		}
		currentTetromino->Draw();
		renderer.Render();
	}
	if (menuRequested)
	{
		mainMenu.StartLoop();
		if (!mainMenu.GetExit())
			ResumeGameplayLoop();
	}
}

void Game::UpdateCurrentTetrominoPosition()
{
	SDL_Rect dstRect = currentTetromino->GetDstRect();
	dstRect.y += currentTetromino->GetTetrominoSize();

	currentTetromino->SetDstRect(&dstRect);
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
