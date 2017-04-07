#pragma once
#include "Tetromino.h"
class PhantomTetromino :
	public Tetromino
{
public:

	PhantomTetromino(ETetrominoType t);
	~PhantomTetromino();

	void CreateBlocks();
};

