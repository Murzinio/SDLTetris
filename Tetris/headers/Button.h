#pragma once
#include "Renderer.h"
#include "VisibleEntity.h"

struct TextureColor;
enum class EButtonType;
enum class EScreenPosition;

class Logger;
class Renderer;

class Button
	: public VisibleEntity
{
private:
	EButtonType type;

	SDL_Texture* texture;
	SDL_Rect dstRect;
	SDL_Rect srcRect;
	SDL_Rect screenRect;

	Logger logger;
	std::string texturePath;

	bool isHighlited{ false };
	bool isPressed{ false };

	void FillTextureRects(Position correction);
	void FillTexture();
	
public:
	Button(EButtonType bt, Position correction);
	~Button();

	void Highlight();
	void UnHighlight();
	bool GetIsHighlited();

	void SetIsPressed(bool value);
	bool GetIsPressed();

	EButtonType GetType();

	SDL_Rect GetDstRect();
	SDL_Rect GetScreenRect();

	void AddToRenderQueue();

	void Draw();
};

inline SDL_Rect Button::GetDstRect()
{
	return dstRect;
}


inline SDL_Rect Button::GetScreenRect()
{
	return dstRect;
}

inline EButtonType Button::GetType()
{
	return type;
}