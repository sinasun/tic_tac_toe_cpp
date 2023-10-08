#include "Board.h"
#include <iostream>

int main() {
	Board board;
	while(board.check_winner() == -1) {
		board.print_board();
		int player = board.get_turn();
		int choice;
		std::cout << "Player " << player << " turn: " << std::endl;
		std::cin >> choice;
		int row = choice / 3;
		int column = choice % 3;
		board.update_board(row, column, player);
	}
	std::cout << "*******************************" << std::endl;
	board.print_board();
	int result = board.check_winner();
	switch (result) {
		case 0:
			std::cout << "Draw" << std::endl;
			break;
		case 1:
			std::cout << "Player 1 [X] Won!" << std::endl;
			break;
		case 2:
			std::cout << "Player 2 [O] Won!" << std::endl;
			break;
	}
}
