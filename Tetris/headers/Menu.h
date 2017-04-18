#pragma once
#include "Logger.h"
#include "InputHandler.h"
#include <SDL.h>
#include <vector>
#include <string>
#include "Button.h"

enum class EButtonType;
enum class EScreenPosition;


class Menu :
	public VisibleEntity
{
private:
	Logger logger;
	InputHandler inputHandler;

	EMenuType type;

	SDL_Rect dstRect{0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	int buttonCount{ 0 };
	bool exit{ false };
	std::vector<std::shared_ptr<Button>> buttons;
	bool optionsRequested{ false };
	bool mainMenuRequested{ false };
	bool buttonPressHandled{ false };
public:
	Menu(EMenuType menuType);
	~Menu();
	std::shared_ptr<Button> NewButton(EButtonType bt, Position correction);
	void CreateButtons();
	bool IsAnyButtonHighlited();
	bool GetExit();
	bool GetOptionsRequested();
	bool GetMainMenuRequested();
	void StartLoop();

	void Draw();
};

inline bool Menu::GetOptionsRequested()
{
	return optionsRequested;
}

inline bool Menu::GetMainMenuRequested()
{
	return mainMenuRequested;
}