#include "..\headers\VisibleEntity.h"

Logger VisibleEntity::logger;
Renderer* VisibleEntity::renderer;
Textures VisibleEntity::textures;

int VisibleEntity::gameBoardWidth;
int VisibleEntity::gameBoardHeight;

int VisibleEntity::tetrominoBlockSize;

VisibleEntity::VisibleEntity()
{
}


VisibleEntity::~VisibleEntity()
{
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
	textures.button_resume.LoadTexture("mainMenu\\buttons\\resume.png");
	textures.button_options.LoadTexture("mainMenu\\buttons\\options.png");
	textures.button_exit.LoadTexture("mainMenu\\buttons\\exit.png");

	/*Game board*/
	textures.GameBoard.LoadTexture("gameBoard\\gameBoard.png");
	textures.GameBoardGrid.LoadTexture("gameBoard\\gameBoardGrid.png");
	textures.ScoreBoard.LoadTexture("gameBoard\\scoreBoard.png");

	/*Tetrominos*/
	textures.TetrominoBlock_Yellow.LoadTexture("tetrominoBlocks\\Yellow.png");

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
