#pragma once

#include <SDL.h>

#include "Logger.h"
#include "Button.h"
#include "enums.h"
#include "constants.h"
#include "Button.h"
#include "VEScaledDimensions.h"

struct MousePosition 
{
	int x;
	int y;
};

enum class EButtonType;
enum class ETetrominoMove;

class Button;
class InputHandler
{
private:
	SDL_Event event;

	std::shared_ptr<Button> currentButton;
	SDL_Rect buttonRect;
	MousePosition mousePosition;
	Logger logger;
	bool isMouseOverButton{ false };
	bool exitRequested{ false };
	bool menuRequested{ false };

	bool moveRequested{ false };
	bool fastPlacementRequested{ false };
	ETetrominoMove move;

	bool isMouseDown{ false };
	EButtonType buttonToHighlight;
public:
	InputHandler();
	~InputHandler();
	bool GetExitRequested();
	bool GetMenuRequested();

	bool GetMoveRequested();
	bool GetFastPlacementRequested();
	ETetrominoMove GetMove();

	void HandleEvents();
	bool IsButtonPressed(std::shared_ptr<Button> button);
	void HandleButtonEvents(std::shared_ptr<Button> button);
	bool IsMouseOverButton(std::shared_ptr<Button> button);
	void ClearButtonMouseChecks();
	EButtonType GetButtonToHighlight();
};

inline bool InputHandler::GetMoveRequested()
{
	return moveRequested;
}

inline ETetrominoMove InputHandler::GetMove()
{
	return move;
}

inline EButtonType InputHandler::GetButtonToHighlight()
{
	return buttonToHighlight;
}
