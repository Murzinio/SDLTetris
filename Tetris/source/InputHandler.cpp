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
	int x, y;

	isMouseDown = false;
	menuRequested = false;
	moveRequested = false;

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
			}
		}
	}
}

void InputHandler::HandleButtonEvents(Button* button)
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

bool InputHandler::IsMouseOverButton(Button* button)
{
	SDL_Rect buttonRect = button->GetScreenRect();
	if (
		(mousePosition.x > buttonRect.x && mousePosition.x < buttonRect.x + BUTTON_WIDTH)
		&& (mousePosition.y > buttonRect.y && mousePosition.y < buttonRect.y + BUTTON_HEIGHT)
		)
		return true;

	return false;
}

bool InputHandler::IsButtonPressed(Button* button)
{
	SDL_Rect buttonRect = button->GetScreenRect();
	if (!IsMouseOverButton(button))
		return false;
	else if (isMouseDown)
		return true;

	return false;
}

EButtonType InputHandler::GetButtonToHighlight()
{
	return buttonToHighlight;
}

void InputHandler::ClearButtonMouseChecks()
{
	isMouseOverButton = false;
	buttonToHighlight = EButtonType::DEFAULT_BUTTON;
}

bool InputHandler::GetMoveRequested()
{
	return moveRequested;
}

ETetrominoMove InputHandler::GetMove()
{
	return move;
}