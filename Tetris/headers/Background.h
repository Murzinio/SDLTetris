#pragma once
#include "VisibleEntity.h"

enum class EBackground;

class Background :
	public VisibleEntity
{
private:
	EBackground type;
	SDL_Texture* texture;

	void FillTexture();
public:
	Background();
	~Background();
};

