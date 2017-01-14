#pragma once

#include "Object.h"

class Piece : public Object
{
public:
	Piece();
	Piece(int width, int height, char num, const char* shape);
	virtual ~Piece();

	inline char get_num() const { return num; }

	void rotate(Piece& piece) const;

private:
	char num;
};

