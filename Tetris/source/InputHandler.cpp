#include "..\headers\InputHandler.h"

InputHandler::InputHandler()
{
	logger.Log("InputHandler initialized.");
}


InputHandler::~InputHandler()
{
}

void InputHandler::HandleEvents()
{
	isMouseDown = false;
	menuRequested = false;
	moveRequested = false;
	fastPlacementRequested = false;

	while (SDL_PollEvent(&event) != 0)
	{
		SDL_GetMouseState(&mousePosition.x, &mousePosition.y);

		isMouseDown = false;
		menuRequested = false;
		if (event.type == SDL_QUIT)
		{
			exitRequested = true;
			logger.Log("Exit requested.");
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			isMouseDown = true;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				menuRequested = true;
				logger.Log("Menu requested.");
				break;

			case SDLK_LEFT:
				moveRequested = true;
				move = ETetrominoMove::LEFT;
				break;

			case SDLK_RIGHT:
				moveRequested = true;
				move = ETetrominoMove::RIGHT;
				break;
			case SDLK_DOWN:
				moveRequested = true;
				move = ETetrominoMove::DOWN;
				break;
			case SDLK_UP:
				moveRequested = true;
				move = ETetrominoMove::ROTATE;
				break;
			case SDLK_SPACE:
				fastPlacementRequested = true;
				break;
			}
		}
	}
}

void InputHandler::HandleButtonEvents(std::shared_ptr<Button> button)
{
	currentButton = button;
}

bool InputHandler::GetExitRequested()
{
	return exitRequested;
}

bool InputHandler::GetMenuRequested()
{
	return menuRequested;
}

bool InputHandler::IsMouseOverButton(std::shared_ptr<Button>  button)
{
	SDL_Rect buttonRect = button->GetScreenRect();
	if (
		(mousePosition.x > buttonRect.x && mousePosition.x < buttonRect.x + GLOBAL_buttonWidth)
		&& (mousePosition.y > buttonRect.y && mousePosition.y < buttonRect.y + GLOBAL_buttonHeight)
		)
		return true;

	return false;
}

bool InputHandler::IsButtonPressed(std::shared_ptr<Button> button)
{
	SDL_Rect buttonRect = button->GetScreenRect();
	if (!IsMouseOverButton(button))
		return false;
	else if (isMouseDown)
		return true;

	return false;
}



void InputHandler::ClearButtonMouseChecks()
{
	isMouseOverButton = false;
	buttonToHighlight = EButtonType::DEFAULT_BUTTON;
}

bool InputHandler::GetFastPlacementRequested()
{
	return fastPlacementRequested;
}



