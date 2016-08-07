
#include "game.h"
using namespace std;
//initializing the colour changing in built functions
HANDLE hCon;

//function to change the colour
	//uises the colour and needs the colour input http://www.cplusplus.com/forum/beginner/77879/ used as reference
void SetColour(pallete p) {
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, p);
}

//constructor for the class game
fgame::fgame() {

	//filling the grid
	for (int a = 0;a<9;a++) {
		grid[a] = '-';
	}

	//makes arrays of pointers corrsponding to rows, columns and diagonals of the board 
	grdpoint = grid;    //pointer initialization 
	r1[0] = grdpoint;r1[1] = grdpoint + 1;r1[2] = grdpoint + 2; //starting from here the pointers arrays corrspond to rows1,2,3:cols 1,2,3 nad diagonals 1 & 2 respectively
	r2[0] = grdpoint + 3;r2[1] = grdpoint + 4;r2[2] = grdpoint + 5; //assigning pointer values in grid to row 2
	r3[0] = grdpoint + 6;r3[1] = grdpoint + 7;r3[2] = grdpoint + 8; //assigning pointer values in grid to row 3
	c1[0] = grdpoint;c1[1] = grdpoint + 3;c1[2] = grdpoint + 6; //assigning pointer values in grid to column 1
	c2[0] = grdpoint + 1;c2[1] = grdpoint + 4;c2[2] = grdpoint + 7; //assigning pointer values in grid to column 2
	c3[0] = grdpoint + 2;c3[1] = grdpoint + 5;c3[2] = grdpoint + 8; //assigning pointer values in grid to column 3
	di1[0] = grdpoint;di1[1] = grdpoint + 4;di1[2] = grdpoint + 8; //assigning pointer values in grid to diagonal 1
	di2[0] = grdpoint + 2;di2[1] = grdpoint + 4;di2[2] = grdpoint + 6; //assigning pointer values in grid to diagonal 2
}

//move validation
bool fgame::validation(int move) {
	if (grid[move] == '-') {	//returning true because there is a placeholder so move can be done
		return true;
	}
	//error handling
	if (move<=9 && grid[move] != '-') {	//move validation and error handling
		SetColour(RED);
		cout << "This position has already been used\n";	//error message
		SetColour(WHITE);
	}
	//error message
	if (move>9 && move<0) {
		SetColour(RED);
		cout << "That is an invalid move\n\n";
		SetColour(WHITE);
	}

	return false;
}

//clearinmg the screen(refresh)
void fgame::clear() {
	system("cls");
}

bool fgame::winningsets(array<char*, 3> k) {
	array<char*, 3>::iterator creator; //instantiating the iterator named creator
	creator = k.begin(); //allows me to iterate through the winning set to make sure that a win is triggered correctly
	if (**creator == **(creator + 1) && **(creator + 1) == **(creator + 2)) { //pointer creation
		return true;
	}

	else {
		return false; //will return as not a win
	}
}

//checking the gamestate if the game
state fgame::gstate() {
	if ((winningsets(r1) == true && *r1[0] != '-') || (winningsets(r2) == true && *r2[0] != '-') //winning sets true and pointer not equal to placeholder
		|| (winningsets(r3) == true && *r3[0] != '-') || (winningsets(c1) == true && *c1[0] != '-') //winning sets true and pointer not equal to placeholder
		|| (winningsets(c2) == true && *c2[0] != '-') || (winningsets(c3) == true && *c3[0] != '-') //winning sets true and pointer not equal to placeholder
		|| (winningsets(di1) == true && *di1[0] != '-') || (winningsets(di2) == true && *di2[0] != '-')) { //winning sets true and pointer not equal to placeholder
		//checking the winning combinations and that they dont equlka the placeholder
			//retruns w or win gamestate
		return W;
	}
		//if the board is full then game is a draw
	else if (isboardfull() == true) {
		return D;
	}

	else {
		//continue game if there is no win or draw
		return CGAME;
	}

}

//checking if the board is full
bool fgame::isboardfull() {
	//for loop to check if the board is full, if the board is full with placeholder then false. If not then set to true
	for (int i = 0;i<9;i++) {
		if (grid[i] == '-') {
			return false;
		}
	}
	return true;
}

//showing the updated board
void fgame::showboard() {
	//refreshing the screen
	clear();
		//showing the updates
		cout << " " << grid[0] << " " << grid[1] << " " << grid[2] << "  \n " << grid[3] << " " << grid[4] << " " << grid[5] << " \n " << grid[6] << " " << grid[7] << " " << grid[8] << "  \n\n"; //showimg the places in the array
}

//showing the win/draw board after the gmae has finished
void fgame::showwincombo() {
	//refreshing the screen
	clear();
	//if winning sets for row 1 is true
	if (winningsets(r1) == true) {
		cout << " ";
		//function for showing win colour
		winnercolour(grid[0]);
		cout << " ";
		winnercolour(grid[1]);
		cout << " ";
		winnercolour(grid[2]);
		cout << " \n " << grid[3] << " " << grid[4] << " " << grid[5] << " \n " << grid[6] << " " << grid[7] << " " << grid[8] << " \n\n";
		winner(*r1[0]); //shows the winner and associates it to the pointer of r1 created earlier
	}

	//if winning sets for row 2 is true
	else if (winningsets(r2) == true) {
		cout << " " << grid[0] << " " << grid[1] << " " << grid[2] << " \n ";
		winnercolour(grid[3]);
		cout << " ";
		winnercolour(grid[4]);
		cout << " ";
		winnercolour(grid[5]);
		cout << " \n " << grid[6] << " " << grid[7] << " " << grid[8] << " \n";
		winner(*r2[0]); //shows the winner and associates it to the pointer of r2 created earlier
	}

	//if winning sets for row 3 is true
	else if (winningsets(r3) == true) {
		cout << " " << grid[0] << " " << grid[1] << " " << grid[2] << " \n" << grid[3] << " " << grid[4] << " " << grid[5] << " \n ";
		winnercolour(grid[6]);
		cout << " ";
		winnercolour(grid[7]);
		cout << " ";
		winnercolour(grid[8]);
		cout << " \n\n";
		winner(*r3[0]); //shows the winner and associates it to the pointer of r3 created earlier
	}

	//if winning sets for column 1 is true
	else if (winningsets(c1) == true) {
		cout << " ";
		winnercolour(grid[0]);
		cout << " " << grid[1] << " " << grid[2] << " \n ";
		winnercolour(grid[3]);
		cout << " " << grid[4] << " " << grid[5] << " \n ";
		winnercolour(grid[6]);
		cout << " " << grid[7] << " " << grid[8] << "  \n\n";
		winner(*c1[0]); //shows the winner and associates it to the pointer of c1 created earlier
	}

	//if winning sets for column 2 is true
	else if (winningsets(c2) == true) {
		cout << " " << grid[0] << " ";
		winnercolour(grid[1]);
		cout << " " << grid[2] << " \n " << grid[3] << " ";
		winnercolour(grid[4]);
		cout << " " << grid[5] << " \n " << grid[6] << " ";
		winnercolour(grid[7]);
		cout << " " << grid[8] << " \n\n";
		winner(*c2[0]); //shows the winner and associates it to the pointer of c2 created earlier
	}

	//if winning sets for column 3 is true
	else if (winningsets(c3) == true) {
		cout << " " << grid[0] << " " << grid[1] << " ";
		winnercolour(grid[2]);
		cout << " \n " << grid[3] << " " << grid[4] << " ";
		winnercolour(grid[5]);
		cout << " \n " << grid[6] << " " << grid[7] << " ";
		winnercolour(grid[8]);
		cout << " \n\n";
		winner(*c3[0]); //shows the winner and associates it to the pointer of c3 created earlier
	}

	//if winning sets for diagonal 1 is true
	else if (winningsets(di1) == true) {
		cout << " ";
		winnercolour(grid[0]);
		cout << " " << grid[1] << " " << grid[2] << "  \n " << grid[3] << " ";
		winnercolour(grid[4]);
		cout << " " << grid[5] << " \n " << grid[6] << " " << grid[7] << " ";
		winnercolour(grid[8]);
		cout << " \n\n";
		winner(*di1[0]); //shows the winner and associates it to the pointer of di1 created earlier
	}

	//if winning sets for diagonal 2 is true
	else if (winningsets(di2) == true) {
		cout << " " << grid[0] << " " << grid[1] << " ";
		winnercolour(grid[2]);
		cout << " \n " << grid[3] << " ";
		winnercolour(grid[4]);
		cout << " " << grid[5] << " \n ";
		winnercolour(grid[6]);
		cout << " " << grid[7] << " " << grid[8] << "  \n\n";
		winner(*di2[0]); //shows the winner and associates it to the pointer of di created earlier
	}

}

//game winning colour change function (makes code reusable)
void fgame::winnercolour(char c) {
	SetColour(TEAL);
	cout << c;
	SetColour(WHITE);
}

void fgame::winner(char c) { //winner TEXT 
	//of winner is O
	if (c == 'O') {
		SetColour(BLUE);
		cout << player1 << " Has WON, Well DONE!\n";
		SetColour(WHITE);
	}
	//if winner is X
	else if (c == 'X') {
		SetColour(BLUE);
		cout << player2 << " Has WON, Well DONE!\n";
		SetColour(WHITE);
	}
}