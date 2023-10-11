#include "Board.h"

Board::Board(){
	std::cout << "New Board Created" << std::endl;
}
char Board::get_position(int row, int column) {
	if (row >= 3 || column >= 3) {
		return 'E'; //E = error
	}
	if (board[row][column] == 1) {
		return 'X';
	}
	else if (board[row][column] == 2) {
		return 'O';
	} 
	return '0' + (row * 3 + column) ;
}

int Board::get_turn() {
	return turn;
}
void Board::print_board() {
	for (int i = 0; i < 3; ++i) {
		std::cout << "         |         |          " << std::endl;
		for (int j = 0; j < 3; ++j) {
			std::cout << "    " << get_position(i, j);
			if (j != 2) std::cout << "    |";
		}
		std::cout << std::endl << "         |         |          " << std::endl;
		if (i != 2) std::cout << "------------------------------" << std::endl;
	}
}
int Board::check_winner() {
	for (int i = 0; i < 3; ++i) {
		if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return board[0][i];
		}
	}

	for (int i = 0; i < 3; ++i) {
		if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return board[i][0];
		}
	}

	if (board[1][1] != 0 && ((board[1][1] == board[0][0] && board[1][1] == board[2][2]) || (board[1][1] == board[0][2] && board[1][1] == board[2][0]))) {
		return board[1][1];
	}

	//check if there is winning chance 
	for (int i = 0; i < 3; ++i) {
		int count = 0;
		int first;
		int second;

		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 0) continue;
			if (count == 0) first = board[i][j];
			if (count == 1) second = board[i][j];
			count++;
		}
		if (count == 0 || count == 1 || (count == 2 && first == second)) return -1;
	}

	for (int i = 0; i < 3; ++i) {
		int count = 0;
		int first;
		int second;

		for (int j = 0; j < 3; ++j) {
			if (board[j][i] == 0) continue;
			if (count == 0) first = board[j][i];
			if (count == 1) second = board[j][i];
			count++;
		}
		if (count == 0 || count == 1 || (count == 2 && first == second)) return -1;
	}

	int count = 0;
	int first;
	int second;
	int i = 0;
	for (int j = 0; j < 3; ++j && ++i) {
		if (board[j][i] == 0) {
			continue;
		}
		if (count == 0) first = board[j][i];
		if (count == 1) second = board[j][i];
		count++;
	}
	if (count == 0 || count == 1 || (count == 2 && first == second)) return -1;

	count = 0;
	i = 2;
	for (int j = 0; j < 3; ++j && --i) {
		if (board[j][i] == 0) {
			continue;
		}
		if (count == 0) first = board[j][i];
		if (count == 1) second = board[j][i];
		count++;
	}
	if (count == 0 || count == 1 || (count == 2 && first == second)) return -1;

	return 0;
}

int Board::update_board(int row, int column, int player) {
	if (board[row][column] != 0) {
		return -1;	
	}
	board[row][column] = player;
	turn = (player == 1) ? 2 : 1;
	return 0;
}
