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

enum class ETetrominoMove
{
	LEFT,
	RIGHT,
	DOWN,
	UP, // to avoid collisions while rotating
	ROTATE
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
	BLUE,
	ORANGE,
	GREEN,
	RED,
	COUNT,
	PHANTOM
};

enum class ETetrominoType
{
	I,
	O,
	T,
	J,
	L,
	S,
	Z,
	COUNT
};

enum class EPositionAxis
{
	X,
	Y,
};