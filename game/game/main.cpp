//header declarations
#include <iostream> //standard c++ header
#include <string> //the abilty to use strings
#include <stdlib.h>
#include <Windows.h> //ability to change text colours
#include "game.h" //including the game header
#include "playervplayer.h" //including the player vs player header
#include "AI.h" //including the AI header
#include <ctype.h>

using namespace std; //std functions included (cin and cout)
void maingamewithmenu();	//function main play prototpye

//main function
int main() {
	char answer;
	//name badges

	cout << "\tAleem Ur-Rehman\n\t";
	SetColour(RED);
	cout << "\tStudent Number: 24017377 " << endl;
	SetColour(WHITE);
	cout << "\tPress S to start the game:  ";
	cin >> answer;
	//system("pause");
	if (answer = 'S' || 's' ) {
		maingamewithmenu();
		return 0;
	}
}

//main function declaration
void maingamewithmenu() {
	int c1; //variable declaration
	char replay; //variable declaration
	char replay2; //variable declaration
	system("cls");
	cout << "\t\t\tNOUGHTS AND CROSSES\n";
	SetColour(DARKGRAY);
	cout<< "\t\t1. Play Against Another Player \n \t\t2. Player Against AI\n \t\t3. Instructions\n \t\t4. Exit  \n\n";
	SetColour(WHITE);
	cout << "\t Choice: " ;
	cin >> c1; //input from menu output 
	if (c1<=4) {	//will always run as long as input is less than 5
		switch (c1) {	//switch case based on the c1 variable
		case 1: //first case
		{
			system("cls");
			//starts the player vs player game
			playervsplayer A1;
			A1.final();
			break;	//break from case
		}

		case 2:
		{
			system("cls");
			AI A2;	//play aginast the computer declaration
			A2.final();		//play agianst the computer function
			break;
		}

		case 3:
		{
			system("cls");
			//displaying the header
			cout << "\t\t Noughts And Crosses Instructions" << endl;
			cout << "Player 1 is 'O' and Player 2 is 'X'\n The computers name is Wall-e, attempt to beat him!" <<endl;
			//shows the mapping of the grid
			cout << "The following list dipslays how a user can make a choice dependant on the grid of the choices. Type in one of the numbers to make a choice\n\tThe numbers are filled with the '-' placeholder in the actual game\n";
			cout << "\t 1 2 3 \n\t 4 5 6 \n\t 7 8 9 \n\n";
			cout << "\n\n";
			break;
		}

		case 4:
		{
			cout << "Exiting \n\n";	//extitng the menu
			exit(0);
		}
		}
		//starting a game after instructions
		if (c1 == 3) {
			cout << "Do you want to play a game now?\n\tY. Yes \n\tN. No " << endl;
			cout << "Choice: ";
			cin >> replay2;
			if (replay2 == 'Y' || 'y') { //looping back to another game
				maingamewithmenu();
			}
			else if (replay2 == 'N' || 'n') { //exiting
				cout << "Exiting \n\n";
				return;
			}
		}
		//replaying the game
		cout << "\n\t Do You Want to Play Another Game?\n\tY. Yes \n\tN. No \n";
		cin >> replay;	//replay variable acts as input
		if (replay == 'Y' || 'y') {
			maingamewithmenu(); //start the main play function again
		}
		else if (replay == 'N' || 'n') {	//exiting
			cout << "Exiting \n\n"; 
			return;
		}
		else
		{
			cout << "Exiting \n\n";
			return;
		}
	}
	SetColour(RED); // warning and error handling, setting error message to red text
	cout << c1 << " is not a valid option (PLEASE MAKE A SELECTION BETWEEN 1 AND 4)\n\n";
	SetColour(WHITE);
	system("pause");
	maingamewithmenu();
}