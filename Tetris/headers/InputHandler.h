#pragma once
#include "Logger.h"
#include <SDL.h>
#include "Button.h"
#include "enums.h"
#include "constants.h"
#include "Button.h"

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

	Button* currentButton;
	SDL_Rect buttonRect;
	MousePosition mousePosition;
	Logger logger;
	bool isMouseOverButton{ false };
	bool exitRequested{ false };
	bool menuRequested{ false };

	bool moveRequested{ false };
	ETetrominoMove move;

	bool isMouseDown{ false };
	EButtonType buttonToHighlight;
public:
	InputHandler();
	~InputHandler();
	bool GetExitRequested();
	bool GetMenuRequested();

	bool GetMoveRequested();
	ETetrominoMove GetMove();

	void HandleEvents();
	bool IsButtonPressed(Button* button);
	void HandleButtonEvents(Button* button);
	bool IsMouseOverButton(Button* button);
	void ClearButtonMouseChecks();
	EButtonType GetButtonToHighlight();
};

