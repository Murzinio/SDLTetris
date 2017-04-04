#pragma once
#include "Renderer.h"
#include "VisibleEntity.h"

struct TextureColor;
enum class EButtonType;
enum class EScreenPosition;

class Logger;
class Renderer;

struct ButtonCorrection;

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

	void FillTextureRects(ButtonCorrection correction);
	void FillTexture();
	
public:
	Button(EButtonType bt, ButtonCorrection correction);
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

