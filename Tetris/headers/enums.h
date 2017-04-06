#pragma once

enum class EButtonType
{
	START_BUTTON,
	RESUME_BUTTON,
	OPTIONS_BUTTON,
	EXIT_BUTTON,
	DEFAULT_BUTTON
};

enum class EMenuType
{
	MAIN_MENU,
	RESUME_MENU
};

enum class EScreenPosition
{
	POSITION_CENTER,
	POSITION_CENTER_LEFT,
	POSITION_CENTER_RIGHT,
	POSITION_DEFAULT,
	TETROMINO
};

enum class ETetrominoType
{
	I,
	O,
	T,
	J,
	L,
	COUNT
};

enum class ETetrominoMove
{
	LEFT,
	RIGHT,
	DOWN
};

enum class EBackground
{
	HONG_KONG,
	WATER,
	SUNSET
};

enum class EBoardBoundary
{
	LEFT,
	RIGHT,
};

enum class ETetrominoBlockColor
{
	TURQUOISE,
	YELLOW,
	PURPLE,
	BLUE
};

enum class EPositionAxis
{
	X,
	Y,
	Z,
};