#include <iostream>

using namespace std;

void printBoard(string board[]) {
	int i;
	for (i = 0; i < 25; i++) {
		cout << board[i];
		if ((i + 1) % 5 == 0) {
			cout << "" << endl;
		}
		
	}
}

bool checkWin(string board[], string A, int player) {
	// Checks if the player has won by the end of their turn
	if (board[0] == A && board[2] == A && board[4] == A) {
		cout << "\nPlayer " << player << " wins!" << endl;
		return true;
		
	} else if (board[0] == A && board[12] == A && board[24] == A) {
		cout << "\nPlayer " << player << " wins!" << endl;
		return true;
		
	} else if (board[0] == A && board[10] == A && board[20] == A) {
		cout << "\nPlayer " << player << " wins!" << endl;
		return true;
		
	} else if (board[4] == A && board[14] == A && board[24] == A) {
		cout << "\nPlayer " << player << " wins!" << endl;
		return true;
		
	} else if (board[4] == A && board[12] == A && board[20] == A) {
		cout << "\nPlayer " << player << " wins!" << endl;
		return true;
		
	} else if (board[20] == A && board[22] == A && board[24] == A) {
		cout << "\nPlayer " << player << " wins!" << endl;
		return true;
		
	} else if (board[10] == A && board[12] == A && board[14] == A) {
		cout << "\nPlayer " << player << " wins!" << endl;
		return true;
		
	} else if (board[2] == A && board[12] == A && board[22] == A) {
		cout << "\nPlayer " << player << " wins!" << endl;
		return true;
		
	} else {
		return false;
	}
}

void submit(string board[], int callout, string A) {
	// This will set the user's letter on the board
	switch (callout) {
		case 1:
		board[0] = A; // top left
		break;
		
		case 2:
		board[2] = A; // top middle
		break;
		
		case 3:
		board[4] = A; // top right
		break;
		
		case 4:
		board[10] = A; // middle left
		break;
		
		case 5:
		board[12] = A; // center
		break;
		
		case 6:
		board[14] = A; // middle right
		break;
		
		case 7:
		board[20] = A; // lower left
		break;
		
		case 8:
		board[22] = A; // lower middle
		break;
		
		case 9:
		board[24] = A; // lower right
		break;
		
		default:
		cout << "invalid input" << endl;
		
	}
	
	printBoard(board);
	
}

void resetBoard(string board[]) {
	// This will overwrite the board and make it new again
	board[0] = "   ";
	board[2] = "   ";
	board[4] = "   ";
	board[10] = "   ";
	board[12] = "   ";
	board[14] = "   ";
	board[20] = "   ";
	board[22] = "   ";
	board[24] = "   ";
	
}

void startGame(string board[], string legend[]) {
	int N = 25, Rounds = 9, i, callout, player;
	int pass [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	string X = " X ", O = " O ", rematch;
	bool win = false;
	
	
	for (i = 0; i < Rounds; i++) {
		// Player 1 (X)
		if (i % 2 == 0) {
			player = 1;
			cout << "\nPlayer 1: ";
			cin >> callout;
			
			if (pass[callout - 1] == 0) {
				pass[callout - 1] = 1;
				submit(board, callout, X);
				win = checkWin(board, X, player);
			} else {
				cout << "Tile already taken" << endl;
				i--;
			}
			
			
		}
		// Player 2 (O)
		else if(i % 2 == 1) {
			player = 2;
			cout << "\nPlayer 2: ";
			cin >> callout;
			
			if (pass[callout - 1] == 0) {
				pass[callout - 1] = 1;
				submit(board, callout, O);
				win = checkWin(board, O, player);
			} else {
				cout << "Tile already taken" << endl;
				i--;
			}
		}
		
		if (win == true) {
			cout << "Congratulations!" << endl;
			break;
		}
	}
	
	if (win == false) {
		cout << "Draw! No one wins..." << endl;
	}
	
	cout << "\nRematch? (y/n): ";
	cin >> rematch;
	
	if (rematch == "y") {
			resetBoard(board);
			
			cout << "\nBoard reset...\n" << endl;
			printBoard(legend);
			
			startGame(board, legend);
	}
	
}

int main() {
	// This is the legend for playing the game
	string legend [25] = {" 1 ", " | ", " 2 ", " | ", " 3 ", "---", "-|-", "---", "-|-", "---", " 4 ", " | ", " 5 ", " | ", " 6 ", "---", "-|-", "---", "-|-", "---", " 7 ", " | ", " 8 ", " | ", " 9 "};
	
	// This is the board setup (no inputs)
	string board [25] = {"   ", " | ", "   ", " | ", "   ", "---", "-|-", "---", "-|-", "---", "   ", " | ", "   ", " | ", "   ", "---", "-|-", "---", "-|-", "---", "   ", " | ", "   ", " | ", "   "};
	
	
	// Printing
	printBoard(legend);
	
	cout << "\nPlayer 1 (X) | Player 2 (O)\n" << endl;
	
	startGame(board, legend);
	
	cout << "Thank you for playing" << endl;
	
	return 0;
}