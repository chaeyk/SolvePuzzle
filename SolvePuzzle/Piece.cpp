#include "stdafx.h"
#include "Piece.h"

Piece::Piece() : Object(0, 0), num(0)
{
}

Piece::Piece(int width, int height, char num, const char* shape) : Object(width, height), num(num)
{
	put(shape);
}

Piece::~Piece()
{
}

void Piece::rotate(Piece& dst) const
{
	Object::rotate(dst);
	dst.num = num;
}