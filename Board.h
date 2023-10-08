#pragma once
#include <iostream>
// Player 1 is X
// Player 2 is O
class Board {
public:
	Board();
	int get_turn();
	void print_board();
	int check_winner(); // -1 = no winner, 0 = draw, 1 = X, 2 = O
	int update_board(int, int, int);
	char get_position(int, int);
private:
	int board[3][3] = {};
	int turn = 1;
};
