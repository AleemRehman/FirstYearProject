
#include "ai.h"
using namespace std;

AI::AI() {	//constructor to allow adding to the array at random locations
	//operator set to null for the srand in built function (not time based)
	srand((time(NULL)));
	//adding to array using the push back in built function
		//top to bottom
	list.push_back(r1);	//adding to the first row
	list.push_back(r2);	//adding to the second row
	list.push_back(r3);	//adding to the third row
	list.push_back(c1);	//adding to the first column
	list.push_back(c2);	//adding to the second column
	list.push_back(c3);	//adding to the third column
	list.push_back(di1);	//adding to the first diagonal left to right
	list.push_back(di2);	//adding to the first diagonal right to left
	//initialising h corner and m corner to thier corresponding place in the grade using the grid pointers
	hcorners[0] = grdpoint;hcorners[1] = grdpoint + 2;hcorners[2] = grdpoint + 6;hcorners[3] = grdpoint + 8;
	dcorners[0] = grdpoint + 1; dcorners[1] = grdpoint + 3; dcorners[2] = grdpoint + 5; dcorners[3] = grdpoint + 7;
}

void AI::final() {	//main AI gameplay
	//variable declaration
	int incmnt = 1;	//assigning the numerical value of 1 to int i and declaring the variable
	int uchoice;	//the users choice as an int
	char placeholder;	//placeholder declaration either X or O

	//outputting the header
	cout << "NOUGHTS AND CROSSES Vs. AI" << endl;
	//getting the name of the player
	cout << "Player: Enter your Name\n";
	getline(cin, d);
	//getting input of the users name and associating to player 1
	getline(cin, player1);	//getline used as name is not singular character
	
	//computer initialized to Wall-e
	player2 = "Wall-e";
	
	//showing the board and updating the board
	showboard();
	
	//while loop with the state CGAME as its condition/ CGAME represents continue game
	while (gstate() == CGAME) {
		if (incmnt % 2 != 0) {	//will always refelct as true as the modulus of 1 by 2 is still 1
			//setting the placehoder for the user as O 
			placeholder = 'O';
			cout << player1 << " : Enter your Choice:  ";
			cin >> uchoice;	//getting the users choice
			//deciding the computers choice based on move validation for game.cpp
			if (validation(uchoice - 1) == true) {	//choice-1 = place in array
				grid[uchoice - 1] = placeholder;
				showboard();	//updating the board after the computer has made its choice
			}
			else {
				incmnt--;
			}
		}

		else if (incmnt % 2 == 0) {
			cout << player2 << ": has made his Choice\n";
			choice();
			showboard(); //updating the board after the computer has made its choice
		}
		incmnt++;	//increment through the moves only if ther computer has m,ade its choice
	}

	if (gstate() == D) {	//if the gamew is a draw
		SetColour(PINK);	//setting the text colour to pink
		cout << "The Game is a Draw!!!\n";	//outputted statement for draw
		SetColour(WHITE);	//setting text colour back to white
	}

	else if (gstate() == W) {	//if the game has been won
		showwincombo();	//show the winning board/function declared in game.cpp
	}
}

void AI::choice() {	//
	blockPLAYER status;	//initializing the status of blocking a player
	cornerPLAYER cornerstatus;	//initializing the status of cornering a player
	//initializng status as the winblocks function delcared later
	status = WinsBlocks();
	if (status.wins == true) {
		for (int k = 0;k<3;k++) {	//for loop to discover if the placeholder has either an X or -
			if (*list[status.place][k] == '-')	//pointer towards list 
			{
				*list[status.place][k] = 'X';
				list.erase(list.begin() + status.place);
				return;
			}
		}
	}
	//if the AI has thew abilty to block the player
	if (status.blocks == true) {
		for (int k = 0;k<3;k++) {	//for loop to block the player
			if (*list[status.place][k] == '-') {
				*list[status.place][k] = 'X';
				list.erase(list.begin() + status.place);
				return;
			}
		}
	}

	if (grid[4] == '-') {
		grid[4] = 'X';
		return;
	}

	cornerstatus = c_p_h();
	if (cornerstatus.corner == true) {	//if thje AI is able to corner the player
		int ran = rand() % cornerstatus.emptyposition.size();
		*cornerstatus.emptyposition[ran] = 'X';
		cornerstatus.emptyposition.clear();
		return;
	}
	//if the AI con block the player diagonally
	if (cornerstatus.mcorner == true) {
		int ran = rand() % cornerstatus.emptyposition.size();
		*cornerstatus.emptyposition[ran] = 'X';
		cornerstatus.emptyposition.clear();
		return;
	}
}

AI::blockPLAYER AI::WinsBlocks() {	//declaring the blockplayer struct with the winsblocks function
	blockPLAYER status;	//initializing the status blockPLAYER strucy
	//setting both the blocks and wins to false
	status.blocks = false;	
	status.wins = false;

	status.place = 10000;
	for (int i = 0;i<list.size();i++) { //going thjrough ther list
		if (twoequalelements(list[i]) == true) { //if two elements are equal within the array
			status.blocks = true; //block the player
			status.place = i; //the place where the block can be a block
			if (*list[i][0] == 'X' || *list[i][1] == 'X') { //wither or the first and second
				status.wins = true; //status wins set to true
				status.blocks = false; //blocks set to true
				status.place = i; //place set to i
				return status;
			}
		}
	}

	return status;
}



bool AI::twoequalelements(array<char*, 3> current) { 
	//if two elements are equal in the grid
	if ((*current[0] == *current[1] && *current[0] != '-') //not equal to the placeholder
		|| (*current[1] == *current[2] && *current[1] != '-') //not equal to the placeholder
		|| (*current[2] == *current[0] && *current[2] != '-')) { //not equal to the placeholder
		if (*current[0] == '-' || *current[1] == '-' || *current[2] == '-') { //not equal to the placeholder
			return true;
		}
	}

	return false;
}

AI::cornerPLAYER AI::c_p_h() {	//corner the player
	cornerPLAYER status; //the status of corenering the player declaration
	status.corner = false;
	status.mcorner = false;
	int i = 0; //initializing i to 0 so not to repeat for each for loop
	for (i;i<4;i++) { //less then 4 as combos have to be 3
		if (*hcorners[i] == '-') { //corner is a placeholder 
			status.corner = true; //will corner the player
			status.emptyposition.push_back(hcorners[i]);
		}
	}
	if (status.corner == true) {
		return status;
	}

	for (i;i<4;i++) { //less then 4 as combos have to be 3
		if (*dcorners[i] == '-') { //corner is a placeholder 
			status.mcorner = true;
			status.emptyposition.push_back(hcorners[i]);
		}
	}

	return status;
}

AI::~AI() {	//destructor clears AI after entries
	list.clear(); //clearing the list
}