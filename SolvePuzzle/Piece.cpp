#include "stdafx.h"
#include "Piece.h"

char Piece::id = 0;

void Piece::reset_id()
{
	id = 0;
}

Piece::Piece() : Object(0, 0)
{
}

Piece::Piece(int width, int height, const char* shape) : Object(width, height)
{
	if (id == 0) {
		id = 'a';
	}
	else if (id == 'z') {
		id = 'A';
	}
	else if (id == 'Z') {
		std::cerr << "Too many pieces.";
		exit(1);
	}
	else {
		++id;
	}
	put(shape, id);
}

Piece::~Piece()
{
}

void Piece::rotate(Piece& dst) const
{
	Object::rotate(dst);
}