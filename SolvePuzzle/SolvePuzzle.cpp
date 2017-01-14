// SolvePuzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include "Piece.h"

int64_t tried = 0;

bool solve(const Board& board, const std::vector<Piece>& pieces, int pieces_index)
{
	++tried;

	if (tried % 100000 == 0)
		std::cout << tried << std::endl;

	if (pieces_index == pieces.size()) {
		board.print();
		return true;
	}

	const Piece& piece = pieces[pieces_index];
	Piece rotated_pieces[4];

	rotated_pieces[0] = piece;
	piece.rotate(rotated_pieces[1]);
	rotated_pieces[1].rotate(rotated_pieces[2]);
	rotated_pieces[2].rotate(rotated_pieces[3]);

	for (int i = 0; i < 3; ++i) {
		const Piece& rotated = rotated_pieces[i];

		int w = board.get_width() - rotated.get_width();
		int h = board.get_height() - rotated.get_height();

		for (int y = 0; y <= h; ++y) {
			for (int x = 0; x <= w; ++x) {
				Board intermediate;
				if (!board.put(rotated, x, y, intermediate))
					continue;

				if (solve(intermediate, pieces, pieces_index + 1))
					return true;
			}
		}
	}

	return false;
}

void test()
{
	/*
	111555
	122225
	333245
	334445
	*/
	Board board(6, 4);
	std::vector<Piece> pieces;

	Piece::reset_id();
	pieces.push_back(Piece(3, 2, "111" "100"));
	pieces.push_back(Piece(4, 2, "1111" "0010"));
	pieces.push_back(Piece(3, 2, "111" "110"));
	pieces.push_back(Piece(3, 2, "001" "111"));
	pieces.push_back(Piece(3, 4, "111" "001" "001" "001"));


	if (solve(board, pieces, 0))
		std::cout << "SUCCESS!!" << std::endl;
	else
		std::cout << "FAILED!!" << std::endl;
}

void real()
{
	Board board(10, 6);
	std::vector<Piece> pieces;

	Piece::reset_id();
	pieces.push_back(Piece(4, 2, "1111" "0001"));
	pieces.push_back(Piece(3, 2, "101" "111"));
	pieces.push_back(Piece(4, 2, "1111" "0100"));
	pieces.push_back(Piece(3, 3, "111" "001" "001"));
	pieces.push_back(Piece(4, 2, "0011" "1110"));
	pieces.push_back(Piece(3, 3, "110" "010" "011"));
	pieces.push_back(Piece(5, 1, "11111"));
	pieces.push_back(Piece(3, 3, "110" "011" "001"));
	pieces.push_back(Piece(3, 3, "111" "010" "010"));
	pieces.push_back(Piece(3, 3, "010" "111" "010"));
	pieces.push_back(Piece(3, 3, "010" "011" "110"));
	pieces.push_back(Piece(3, 2, "111" "011"));

	if (solve(board, pieces, 0))
		std::cout << "SUCCESS!!" << std::endl;
	else
		std::cout << "FAILED!!" << std::endl;
}

int main()
{
	SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);

	ULONGLONG ullStart = GetTickCount64();

	test();
	//real();

	ULONGLONG ullEnd = GetTickCount64();
	ULONGLONG ms = ullEnd - ullStart;
	if (ms > 1000) {
		ULONGLONG sec = ms / 1000;
		ms = ms % 1000;

		if (sec > 60) {
			ULONGLONG min = sec / 60;
			sec = sec % 60;

			if (min > 60) {
				ULONGLONG hour = min / 60;
				min = min % 60;

				std::cout << hour << " hours ";
			}

			std::cout << min << " minutes ";
		}

		std::cout << sec << '.';
	}
	else {
		std::cout << "0.";
	}

	std::cout << ms << " seconds." << std::endl;

    return 0;
}

