#include "..\headers\VisibleEntity.h"

Logger VisibleEntity::logger;
Renderer* VisibleEntity::renderer;
Textures VisibleEntity::textures;
int VisibleEntity::gameBoardWidth;

VisibleEntity::VisibleEntity()
{
}


VisibleEntity::~VisibleEntity()
{
	//for (auto & x : textures)
		//delete x;
}

/*
	Private
*/


/*
	Public
*/

void VisibleEntity::PassRenderer(Renderer* r)
{
	renderer = r;
}

void VisibleEntity::SetPosition(Position p)
{
	position = p;
}

bool VisibleEntity::LoadTextures()
{
	/*Backgrounds*/
	textures.background_HongKong.LoadTexture("backgrounds\\hong_kong.png");
	if (!textures.background_HongKong.GetSDLTexture())
		return false;
	textures.background_Water.LoadTexture("backgrounds\\water.png");
	if (!textures.background_Water.GetSDLTexture())
		return false;
	textures.background_Sunset.LoadTexture("backgrounds\\sunset.png");
	if (!textures.background_Sunset.GetSDLTexture())
		return false;
	/*Main menu buttons*/
	textures.button_start.LoadTexture("mainMenu\\buttons\\start.png");
	textures.button_options.LoadTexture("mainMenu\\buttons\\options.png");
	textures.button_exit.LoadTexture("mainMenu\\buttons\\exit.png");

	/*Game board*/
	textures.GameBoard.LoadTexture("gameBoard\\gameplayBackground.png");
	textures.ScoreBoard.LoadTexture("gameBoard\\scoreBackground.png");

	/*Tetrominos*/
	textures.Tetromino_O.LoadTexture("tetrominos\\O.png");

	/*Texture Tetromino_I;
	Texture Tetromino_O;
	Texture Tetromino_T;

	Texture Tetromino_J;
	Texture Tetromino_L;

	Texture Tetromino_S;
	Texture Tetromino_Z;
*/

	return true;
}

Textures VisibleEntity::GetTextures()
{
	return textures;
}
