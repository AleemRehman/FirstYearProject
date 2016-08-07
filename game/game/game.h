#ifndef __GAME_H_INCLUDE
#define __GAME_H_INCLUDE


#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
#include <array>

using namespace std;

//won associations 
	//corresponds to row 1, row 2, row 3, col 1, col 2, col 3, diag 1, diag 2
enum WIN_A { Row1 = 1, Row2, Row3, Col1, Col2, Col3, Di1, Di2 };
//state of the game
	//win=w d=draw cgame=continue game
enum state { W = 0, D, CGAME };
//colours
enum pallete { DARKBLUE=1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };
//function to set the colour
void SetColour(pallete p);	//prototype

class fgame
{
public:
		//game constructor
	fgame();
	bool validation(int); //move validation
	bool winningsets(array<char*, 3>); //all winning combinations	
	state gstate(); //the state of the game (uses the enum state)
	void showboard(); //show the updated board after a move
	void showwincombo(); //shows the winning board after game has ended
	void winnercolour(char); //shows winning colour in teal (makes code reusable)
	void winner(char); //winner statement (set to char c)
	void clear();
protected:
		//player initialization
	string player1; //first player 
	string player2; //second player
	string d; //dummy player
		//grid based variables
	char grid[9]; //game grid (array)
	char* grdpoint; //pointer towards placement in array (initialized in game.cpp)
	bool isboardfull(); //checking if the board is full
			//pointers in the array
	array<char*, 3> r1; //row 1 pointer
	array<char*, 3> r2; //row 2 pointer
	array<char*, 3> r3; //row 3 pointer
	array<char*, 3> c1; //column 1 pointer
	array<char*, 3> c2; //column 2 pointer
	array<char*, 3> c3; //column 3 pointer
	array<char*, 3> di1; //diagonal 1 (left to right) pointer
	array<char*, 3> di2; //diagonal 2 (right to left) pointer
	

};

#endif
