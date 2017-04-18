#include "..\headers\Menu.h"

Menu::Menu(EMenuType menuType)
{
	type = menuType;
}


Menu::~Menu()
{
}

void Menu::StartLoop()
{
	bool startGame{ false };
	optionsRequested = false;
	mainMenuRequested = false;
	SDL_Event sdlQuitEvent{ SDL_QUIT };

	renderer->AddToQueue(textures.background_HongKong.GetSDLTexture(), NULL, &dstRect);
	for (auto & x : buttons)
		x->AddToRenderQueue();

	while (!exit && !startGame && !optionsRequested && !mainMenuRequested)
	{
		renderer->Clear();
		renderer->AddToQueue(textures.background_HongKong.GetSDLTexture(), NULL, &dstRect);

		inputHandler.HandleEvents();
		
		for (auto & x : buttons)
		{
			if (inputHandler.IsMouseOverButton(x))
				x->Highlight();
			else if (IsAnyButtonHighlited())
				x->UnHighlight();

			if (inputHandler.IsButtonPressed(x))// && !buttonPressHandled)
			{
				if (x->GetType() == EButtonType::EXIT_BUTTON)
				{
					SDL_PushEvent(&sdlQuitEvent);
				}
				else if (x->GetType() == EButtonType::START_BUTTON)
				{
					startGame = true;
				}
				else if (x->GetType() == EButtonType::RESUME_BUTTON)
				{
					startGame = true;
				}
				else if (x->GetType() == EButtonType::OPTIONS_BUTTON)
				{
					optionsRequested = true;
				}
			}
			x->AddToRenderQueue();
		}
			

		renderer->Render();
		if (inputHandler.GetExitRequested())
			exit = true;
		else if (inputHandler.GetMenuRequested() && type == EMenuType::OPTIONS_MENU)
			mainMenuRequested = true;
	}
}



std::shared_ptr<Button> Menu::NewButton(EButtonType bt, Position correction)
{
	//Button* button = new Button(bt, correction);
	std::shared_ptr<Button> button = std::make_shared<Button>(bt, correction);

	return button;
}

void Menu::CreateButtons()
{
	if(type == EMenuType::MAIN_MENU)
		buttons.push_back(NewButton(EButtonType::START_BUTTON, { 0, 0 }));
	else if (type == EMenuType::RESUME_MENU)
		buttons.push_back(NewButton(EButtonType::RESUME_BUTTON, { 0, 0 }));
	else
	{
		buttons.push_back(NewButton(EButtonType::VIDEO_BUTTON, { 0, 0 }));
		buttons.push_back(NewButton(EButtonType::SOUND_BUTTON, { 0, GLOBAL_buttonHeight }));
		buttons.push_back(NewButton(EButtonType::GAMEPLAY_BUTTON, { 0, GLOBAL_buttonHeight * 2 }));

	}
	
	if (type != EMenuType::OPTIONS_MENU)
	{
		buttons.push_back(NewButton(EButtonType::OPTIONS_BUTTON, { 0, GLOBAL_buttonHeight }));
		buttons.push_back(NewButton(EButtonType::EXIT_BUTTON, { 0, GLOBAL_buttonHeight * 2 }));
	}
}

bool Menu::IsAnyButtonHighlited()
{
	for (auto & x : buttons)
		if (x->GetIsHighlited())
			return true;
	return false;
}

bool Menu::GetExit()
{
	return exit;
}


void Menu::Draw()
{

}
