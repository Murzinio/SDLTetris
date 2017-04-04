#pragma once
#include <vector>

#include "enums.h"
#include "Texture.h"

struct ButtonCorrection
{
	int x;
	int y;
};

struct TextureColor
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
};

struct TetrominoTexture
{
	ETetrominoType type;
	SDL_Texture* texture;
};

struct TetrominoPosition
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
	Texture button_options;
	Texture button_exit;

	/*Game board*/
	Texture GameBoard;
	Texture ScoreBoard;

	/*Tetrominos*/
	Texture Tetromino_I;
	Texture Tetromino_O;
	Texture Tetromino_T;

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

struct Position
{
	int x;
	int y;
};