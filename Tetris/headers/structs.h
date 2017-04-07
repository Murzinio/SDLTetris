#pragma once
#include <vector>

#include "enums.h"
#include "Texture.h"

struct TetrominoTexture
{
	ETetrominoType type;
	SDL_Texture* texture;
};

struct Position
{
	int x;
	int y;
};

struct Textures
{
	/*Backgrounds*/
	Texture background_HongKong;
	Texture background_Water;
	Texture background_Sunset;

	/*Main menu buttons*/
	Texture button_start;
	Texture button_resume;
	Texture button_options;
	Texture button_exit;

	/*Game board*/
	Texture GameBoard;
	Texture ScoreBoard;

	/*Tetrominos*/
	Texture TetrominoBlock_Turquoise;
	Texture TetrominoBlock_Yellow;
	Texture TetrominoBlock_Purple;
	Texture TetrominoBlock_Blue; 
	Texture TetrominoBlock_Orange;
	Texture TetrominoBlock_Green;
	Texture TetrominoBlock_Red;

	Texture Tetromino_J;
	Texture Tetromino_L;

	Texture Tetromino_S;
	Texture Tetromino_Z;

};

struct Options
{
	bool fullscreen;
	struct resolution
	{
		int x;
		int y;
	};

	bool music;
	int musicVolume;

	bool soundEffects;
	int soundEffectsVolume;
};
