#pragma once

#include "Object.h"

class Piece : public Object
{
public:
	Piece();
	Piece(int width, int height, const char* shape);
	virtual ~Piece();

	void rotate(Piece& piece) const;

private:
	static char id;

public:
	static void reset_id();
};

