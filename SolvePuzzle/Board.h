#pragma once

#include "Object.h"

class Piece;

class Board : public Object
{
public:
	Board();
	Board(int width, int height);
	virtual ~Board();

	bool put(const Piece& piece, int x, int y, Board& dst) const;
};

