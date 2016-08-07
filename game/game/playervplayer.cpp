
#include "playervplayer.h"

using namespace std;

void playervsplayer::final() {
	int i = 1, pchoice;
	char mark;
	string cplayer;

	cout << "Noughts And Crosses" << endl;
	cout << "\t Player 1: Enter your Name\n"; //entering the first players name
	getline(cin, d); //bugfixing
	getline(cin, player1);	//getting input for the first users name
	clear();
	cout << "Noughts And Crosses" << endl;
	cout << "\t Player 2: Enter your Name\n"; //enter the second players name
	getline(cin, player2); //input for the second name
	
	clear(); //system cls function declared in game.cpp
	showboard();	//showing the board and updating after a move has been placed in memory
	while (gstate() == CGAME) {
		if (i % 2 != 0) { //always true
			cplayer = player1; //current turn
			mark = 'O';
		}
		else if (i % 2 == 0) {
			cplayer = player2; //current turn
			mark = 'X';
		}
		cout << cplayer << ": Enter your Choice: ";
		cin >> pchoice; //assign to pchoice

		if (validation(pchoice - 1) == true) {	//choice-1 = place in array
			grid[pchoice - 1] = mark;//choice-1 = place in array SET TO MARK
			showboard();
		}
		else {
			i--; //repeating the move
		}
		i++;	//iterating up through the moves
	}
	if (gstate() == D) {
		SetColour(PINK);
		//draw so following message displayed
		cout << "Game is a draw\n";
		SetColour(WHITE);
	}

	else if (gstate() == W) {
		//showing the win board
		showwincombo();
	}

}