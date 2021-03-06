#include "..\headers\VisibleEntity.h"

Logger VisibleEntity::logger;
Renderer* VisibleEntity::renderer;
Textures VisibleEntity::textures;



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

	/*Options menu buttons*/
	textures.button_video.LoadTexture("optionsMenu\\buttons\\video.png");
	textures.button_sound.LoadTexture("optionsMenu\\buttons\\sound.png");
	textures.button_gameplay.LoadTexture("optionsMenu\\buttons\\gameplay.png");

	/*Game board*/
	textures.GameBoard.LoadTexture("gameBoard\\gameBoard.png");
	textures.ScoreBoard.LoadTexture("gameBoard\\scoreBoard.png");

	/*Tetrominos*/
	textures.TetrominoBlock_Yellow.LoadTexture("tetrominoBlocks\\Yellow.png");
	textures.TetrominoBlock_Turquoise.LoadTexture("tetrominoBlocks\\Turquoise.png");
	textures.TetrominoBlock_Purple.LoadTexture("tetrominoBlocks\\Purple.png");
	textures.TetrominoBlock_Blue.LoadTexture("tetrominoBlocks\\Blue.png");
	textures.TetrominoBlock_Orange.LoadTexture("tetrominoBlocks\\Orange.png");
	textures.TetrominoBlock_Green.LoadTexture("tetrominoBlocks\\Green.png");
	textures.TetrominoBlock_Red.LoadTexture("tetrominoBlocks\\Red.png");
	textures.TetrominoBlock_Phantom.LoadTexture("tetrominoBlocks\\Phantom.png");
	
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
