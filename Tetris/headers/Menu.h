#pragma once
#include "Logger.h"
#include "InputHandler.h"
#include <SDL.h>
#include <vector>
#include <string>
#include "Button.h"

#include <memory>

enum class EBoardType;
enum class EButtonType;
enum class EScreenPosition;


class Menu :
	public VisibleEntity
{
private:
	Logger logger;
	InputHandler inputHandler;

	SDL_Rect dstRect{0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	int buttonCount{ 0 };
	bool exit{ false };
	std::vector<Button*> buttons;

	bool buttonPressHandled{ false };
public:
	Menu();
	~Menu();
	Button* NewButton(EButtonType bt, ButtonCorrection correction);
	void CreateButtons(EBoardType bt);
	bool IsAnyButtonHighlited();
	bool GetExit();
	void StartLoop();

	void Draw();
};

