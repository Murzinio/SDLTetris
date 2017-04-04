#include "..\headers\Menu.h"

Menu::Menu()
{
}


Menu::~Menu()
{
	for (auto & x : buttons)
		delete x;
}

void Menu::StartLoop()
{
	bool startGame{ false };
	SDL_Event sdlQuitEvent{ SDL_QUIT };

	//dstRect.w = 1920;
	//dstRect.h = 1080;

	renderer->AddToQueue(textures.background_HongKong.GetSDLTexture(), NULL, &dstRect);
	for (int i = 0; i < buttons.size(); i++)
		buttons[i]->AddToRenderQueue();

	while (!exit && !startGame)
	{
		//SDL_Delay(5);
		renderer->Clear();
		renderer->AddToQueue(textures.background_HongKong.GetSDLTexture(), NULL, &dstRect);

		inputHandler.HandleEvents();
		
		for (auto & x : buttons)
		{
			//x->SetIsPressed(false);
			if (inputHandler.IsMouseOverButton(x))
				x->Highlight();
			else if (IsAnyButtonHighlited())
				x->UnHighlight();

			if (inputHandler.IsButtonPressed(x))// && !buttonPressHandled)
			{
				logger.Log("pressed");
				//buttonPressHandled = true;
				if (x->GetType() == EButtonType::EXIT_BUTTON)
				{
					//eventToPush.type = SDL_QUIT;
					SDL_PushEvent(&sdlQuitEvent);
				}
				else if (x->GetType() == EButtonType::START_BUTTON)
				{
					//eventToPush.type = SDL_QUIT;
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



Button* Menu::NewButton(EButtonType bt, ButtonCorrection correction)
{
	Button* button = new Button(bt, correction);
	return button;
}

void Menu::CreateButtons(EBoardType boardT)
{
	switch (boardT)
	{
		case EBoardType::MAIN_MENU:
			buttons.push_back(NewButton(EButtonType::START_BUTTON, { 0, 0 }));
			buttons.push_back(NewButton(EButtonType::OPTIONS_BUTTON, { 0, BUTTON_HEIGHT }));
			buttons.push_back(NewButton(EButtonType::EXIT_BUTTON, { 0, BUTTON_HEIGHT * 2 }));
			break;
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