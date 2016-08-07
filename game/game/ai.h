#ifndef __AI_H_INCLUDE
#define __AI_H_INCLUDE
#include "game.h"
#include <vector>
#include <time.h>

using namespace std;

enum specifier { CORNERS = 0, MIDDLE_CORNERS };	//cornering horizontally and cornering diagonally
enum status { WINS, BLOCK, NONE };	//AI status 

class AI : public fgame	//inheriting the main game class
{
	//protected variables
protected:
	struct blockPLAYER {	//struct containing multiple var types associated
		bool wins;	//winning the game as AI (true or false)
		bool blocks;	//AI blocking the player (true or false)
		int place;	//AI placing placeholders into the grid
	};
	struct cornerPLAYER {	//struct containing multiple var types associated
		bool corner;	//AI cornering the horizontally (true or false)
		bool mcorner;	//AI cornering the diagonally (true or false)
		vector<char*> emptyposition;	//pointer towards empty poditions within the array
	};
	vector<array<char*, 3>> list; //list #array#
	vector<status> statuslist;
	array<char*, 4> hcorners; //corners
	array<char*, 4> dcorners; //cotners
public:
	AI();
	void final();	//ai gamemode
	void choice();	//ai choice
	blockPLAYER WinsBlocks();	//winning byblocking
	cornerPLAYER c_p_h();	//corner placement
	bool twoequalelements(array<char*, 3>);
	~AI(); //destructor

};
#endif
