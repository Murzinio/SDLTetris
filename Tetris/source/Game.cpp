#include "..\headers\Game.h"

Game::Game() : dummyEntity(), gameplayManager(&inputHandler, &renderer)//: mainMenu(&renderer)//, gameBoard(&renderer)
{
	//logger.ClearLogIfNeeded();
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
	//InitGameBoard();
	//backgrounds = mainMenu.GetBackgrounds();
	//std::vector<SDL_Texture*> gameBoardTextures{ gameBoard.GetGameBoardTextures() };

	////dummyTetromino = new Tetromino(&renderer, ETetrominoType::TYPE_O);
	//dummyTetromino->LoadTextures();
	//tetrominoTextures = dummyTetromino->GetTextures();
	////allTetrominos.push_back(dummyTetromino);

	//allTetrominos.push_back(new Tetromino(&renderer, ETetrominoType::TYPE_O));
	//allTetrominos[1]->PassTextures(dummyTetromino->GetTextures());

	//
	//
	////previous_update = std::chrono::high_resolution_clock::now();
	//logger.Log("Initialising game loop...");
	//exit = false;
	//while (!exit)
	//{
	//	//SDL_Delay(1000);
	//	renderer.Clear();
	//	renderer.AddToQueue(backgrounds[2], EScreenPosition::POSITION_DEFAULT, NULL, NULL, false);

	//	dstRect = { 0, 0, SCREEN_WIDTH - (SCREEN_WIDTH / 4), SCREEN_HEIGHT - (SCREEN_HEIGHT / 4) };
	//	renderer.AddToQueue(gameBoardTextures[1], EScreenPosition::POSITION_CENTER, NULL, &dstRect, false);

	//	dstRect = { 0, 0, (SCREEN_WIDTH - (SCREEN_WIDTH / 4)) / 4, SCREEN_HEIGHT - (SCREEN_HEIGHT / 4) };
	//	renderer.AddToQueue(gameBoardTextures[0], EScreenPosition::POSITION_CENTER_RIGHT, NULL, &dstRect, false);

	//	//UpdateGameplay();
	//	framesCounter++;
	//	renderer.Render();
	//	inputHandler.HandleEvents();
	//	if (inputHandler.GetExitRequested())
	//		exit = true;
	//	else if (inputHandler.GetMenuRequested())
	//	{
	//		renderer.Clear();
	//		mainMenu.StartLoop();
	//		if (mainMenu.GetExit())
	//			break;
	//	}
	//	
	//}
	//Exit();
	//SDL_Delay(1000);
	//	renderer.Clear();
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
	//dstRect.y += 500;

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
			//gameplayManager.UpdateGameplay();
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
