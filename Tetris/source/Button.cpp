#include "..\headers\Button.h"

Button::Button(EButtonType bt, ButtonCorrection correction)
{
	type = bt;
	FillTextureRects(correction);
	FillTexture();
}


Button::~Button()
{
}

void Button::FillTexture()
{
	switch (type)
	{
		case EButtonType::START_BUTTON:
			texture = textures.button_start.GetSDLTexture();
			break;
		case EButtonType::RESUME_BUTTON:
			texture = textures.button_resume.GetSDLTexture();
			break;
		case EButtonType::OPTIONS_BUTTON:
			texture = textures.button_options.GetSDLTexture();
			break;
		case EButtonType::EXIT_BUTTON:
			texture = textures.button_exit.GetSDLTexture();
			break;
	}
}

void Button::FillTextureRects(ButtonCorrection correction)
{
	dstRect.w = 512;
	dstRect.h = 128;
	dstRect.x = SCREEN_WIDTH / 2 + correction.x - dstRect.w / 2;
	dstRect.y = SCREEN_HEIGHT / 2 + correction.y - dstRect.h / 2;

	srcRect.w = 512;
	srcRect.h = 128;
	srcRect.x = 0;
	srcRect.y = 0;
}

void Button::AddToRenderQueue()
{
	renderer->AddToQueue(texture, &srcRect, &dstRect);
}



void Button::Highlight()
{
	srcRect.y = 128;
	isHighlited = true;
}

void Button::UnHighlight()
{
	srcRect.y = 0;
	isHighlited = false;
}

bool Button::GetIsHighlited()
{
	return isHighlited;
}

bool Button::GetIsPressed()
{
	return isPressed;
}

void Button::SetIsPressed(bool value)
{
	isPressed = true;
}

void Button::Draw()
{

}