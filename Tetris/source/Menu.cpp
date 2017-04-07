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
	SDL_Event sdlQuitEvent{ SDL_QUIT };

	renderer->AddToQueue(textures.background_HongKong.GetSDLTexture(), NULL, &dstRect);
	for (auto & x : buttons)
		x->AddToRenderQueue();

	while (!exit && !startGame)
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
				logger.Log("pressed");
				if (x->GetType() == EButtonType::EXIT_BUTTON)
				{
					SDL_PushEvent(&sdlQuitEvent);
				}
				else if (x->GetType() == EButtonType::START_BUTTON)
				{
					startGame = true;
					logger.Log("start game");
				}
				else if (x->GetType() == EButtonType::RESUME_BUTTON)
				{
					startGame = true;
					logger.Log("start game");
				}
			}
				

			x->AddToRenderQueue();
		}
			

		renderer->Render();
		if (inputHandler.GetExitRequested())
			exit = true;
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
	else
		buttons.push_back(NewButton(EButtonType::RESUME_BUTTON, { 0, 0 }));

	buttons.push_back(NewButton(EButtonType::OPTIONS_BUTTON, { 0, GLOBAL_buttonHeight }));
	buttons.push_back(NewButton(EButtonType::EXIT_BUTTON, { 0, GLOBAL_buttonHeight * 2 }));
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
