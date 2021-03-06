#pragma once

#include <memory>

#include <SDL.h>
#include <SDL_image.h>

#include "Renderer.h"

#include "structs.h"
#include "VEScaledDimensions.h"

using namespace VEScaledDimensions;

class Renderer;
class Texture;

struct Textures;
struct Position;

class VisibleEntity
{
private:
	Position position{ 0, 0 };
protected:
	static Logger logger;
	static Renderer* renderer;
	static Textures textures;

public:
	VisibleEntity();
	virtual ~VisibleEntity() = 0;

	void PassRenderer(Renderer* r);
	
	void SetPosition(Position p);

	bool LoadTextures();
	Textures GetTextures();

	void virtual Draw() = 0;
};

