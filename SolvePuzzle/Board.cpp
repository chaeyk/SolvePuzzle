#include "stdafx.h"
#include "Board.h"
#include "Piece.h"

Board::Board()
{
}

Board::Board(int width, int height) : Object(width, height)
{
	clear();
}

Board::~Board()
{
}

static bool is_closed(const Board& board, int x, int y)
{
	if (board.at(x, y) != '0')
		return false;

	bool up = (y == 0) || board.at(x, y - 1) != '0';
	bool down = (y == board.get_height() - 1) || board.at(x, y + 1) != '0';
	bool left = (x == 0) || board.at(x - 1, y) != '0';
	bool right = (x == board.get_width() - 1) || board.at(x + 1, y) != '0';

	return up && down && left && right;
}

bool Board::put(const Piece& piece, int x, int y, Board& dst) const
{
	dst = *this;

	int pwidth = piece.get_width();
	int pheight = piece.get_height();
	for (int i = 0; i < pwidth; ++i) {
		for (int j = 0; j < pheight; ++j) {
			char id = piece.at(i, j);
			if (id == '0')
				continue;

			if (dst.at(x + i, y + j) != '0') {
				return false;
			}

			dst.at(x + i, y + j) = id;
		}
	}

	// 새로 놓은 조각으로 인해 1x1 이하의 닫힌 공간이 생기면 실패다.
	int check_startx = std::max(x - 1, 0);
	int check_endx = std::min(x + pwidth, get_width());
	int check_starty = std::max(y - 1, 0);
	int check_endy = std::min(y + pheight, get_height());
	for (int i = check_startx; i <= check_endx; ++i) {
		for (int j = check_starty; j <= check_endy; ++j) {
			if (is_closed(dst, x, y))
				return false;
		}
	}

	return true;
}
