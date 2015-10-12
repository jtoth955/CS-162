/***********************************************************************************
*Filename: main.cpp
*Name: John R Toth
*Date: 4/5/15
*Description: Assignment 1: Conway's Game of Life
*Input: Prompt for user to make coordinate selection and weapon of choice
*Output: Displays cell change with each iteration of the game
***********************************************************************************/

#include <iostream> 

using namespace std;

const int 	ROWS = 80,
			COLS = 60,
			BUFF = 20;

void userInput();
void initBoard(int, int);
void gameLoop(int a[ROWS][COLS]); 
void dispBoard(int b[ROWS][COLS]);
void mainBoard(int c[ROWS][COLS]);
void generation(int d[ROWS][COLS]);
void replay(int e[ROWS][COLS]);


//main fn, asks user to input initial coordinates. 
int main()
{

 	userInput();


return 0;
}
/***********************************************************************************
*Description: initBoard fn, initializes board, updates user selection for coordinates
*and weapon of choice
*Parameters: None
***********************************************************************************/
void initBoard(int xCoord, int yCoord, int pattern)
{	
	int array[ROWS][COLS];
	int x, y;
	for(int x = 0; x < ROWS; x++)
	{
		for(int y = 0; y < COLS; y++)
		{
			array[x][y] = 0;
		}
	}

//row and column coordinates input by user
//option 1 == glider pattern
if (pattern == 1)
{	
array[xCoord][yCoord+1] = 1;
array[xCoord+2][yCoord+2] = 1;
array[xCoord+1][yCoord+3] = 1;
array[xCoord][yCoord+1] = 1;
array[xCoord][yCoord+1] = 1;
array[xCoord+2][yCoord+2] = 1;
array[xCoord+1][yCoord+3] = 1;
array[xCoord-2][yCoord+1] = 1;
array[xCoord+2][yCoord+2] = 1;
array[xCoord+1][yCoord+3] = 1;
array[xCoord+3][yCoord+2] = 1;
array[xCoord+3][yCoord+3] = 1;
array[xCoord][yCoord+1] = 1;
array[xCoord+4][yCoord+4] = 1;
array[xCoord+4][yCoord+5] = 1;
}

//option 2 == glider gun
if(pattern == 2)
{
array[xCoord-2][yCoord+1] = 1;
array[xCoord+2][yCoord+2] = 1;
array[xCoord+1][yCoord+3] = 1;
array[xCoord+3][yCoord+2] = 1;
array[xCoord+3][yCoord+3] = 1;
array[xCoord-1][yCoord+1] = 1;
array[xCoord+4][yCoord-4] = 1;
array[xCoord+4][yCoord-5] = 1;
array[xCoord-3][yCoord+1] = 1;
array[xCoord-3][yCoord+2] = 1;
array[xCoord-4][yCoord+3] = 1;
array[xCoord+2][yCoord+2] = 1;
array[xCoord+1][yCoord+3] = 1;
}

//option 3 == cannon
if(pattern == 3)
{
array[xCoord][yCoord+1] = 1;
array[xCoord+2][yCoord+2] = 1;
array[xCoord+1][yCoord+3] = 1;
array[xCoord][yCoord+1] = 1;
array[xCoord+2][yCoord+2] = 1;
array[xCoord+1][yCoord+3] = 1;
array[xCoord-2][yCoord+1] = 1;
array[xCoord+2][yCoord+2] = 1;
array[xCoord+1][yCoord+3] = 1;
array[xCoord+3][yCoord+2] = 1;
array[xCoord+3][yCoord+3] = 1;
array[xCoord-1][yCoord+1] = 1;
array[xCoord+4][yCoord-4] = 1;
array[xCoord+4][yCoord-5] = 1;
array[xCoord-3][yCoord+1] = 1;
}

//oscillator initialization
	array[32][34] = 1;
	array[33][34] = 1;
	array[34][34] = 1;
	array[35][34] = 1;
	array[36][34] = 1;
	array[25][23] = 1;
	array[25][24] = 1;
	array[25][25] = 1;
	array[25][26] = 1;
	array[25][27] = 1;

dispBoard(array);
}
/***********************************************************************************
*Description: dispBoard fn, displays limited portion of the board with a buffer fn 
*Parameters: None
***********************************************************************************/
void dispBoard(int b[ROWS][COLS])
{

	for(int x = BUFF; x < (ROWS - BUFF); x++)
	{
		for(int y = BUFF; y < (COLS - BUFF); y++)
		{
			cout << b[x][y] << " ";
		}
	cout << endl;
	}
cout << endl; 

gameLoop(b);
}
/***********************************************************************************
*Description: gameLoop fn, receives updated board information from replay fn, then 
*forwards to mainBoard fn
*Parameters: None
***********************************************************************************/
void gameLoop(int a[ROWS][COLS])
{


mainBoard(a);
}
/***********************************************************************************
*Description: mainBoard fn, receives updated board from gameLoop
*Parameters: None
***********************************************************************************/
void mainBoard(int c[ROWS][COLS])
{
	
				

generation(c);
}
/***********************************************************************************
*Description: generation fn, copies board, assesses neighboring cells, copies board 
*back and sends updated board to replay fn
*Parameters: None
***********************************************************************************/
void generation(int d[ROWS][COLS])
{
int cpy[ROWS][COLS];
//copy of mainBoard array made so that neighbors can be assessed and rules applied
for(int x = 0; x < ROWS; x++)
		{
			for(int y = 0; y < COLS; y++)
			{
				cpy[x][y] = d[x][y];
			}

		}

int count = 0;
	for(int x = 0; x < ROWS; x++)
		{
		for(int y = 0; y < COLS; y++)
			{									//step through all coordinates and assess neighbor cells
			count = cpy[x][y]+					//referenced runnable.com (http://bit.ly/1GAWa7I) for algorithm ideas
			cpy[x-1][y-1] +						//slight similarity in concept 
			cpy[x-1][y] +
			cpy[x-1][y+1] +
			cpy[x][y-1] +
			cpy[x][y+1]+
			cpy[x+1][y-1] +
			cpy[x+1][y] +
			cpy[x+1][y+1];
		
				//cell dies of lonliness
				if((count == 1)||(count == 0)) 			//rules
				{
					cpy[x][y] = 0;
				}				
				//cell dies of overcrowding
				if(count > 3)
				{
					cpy[x][y] = 0;
				}
				//birth of a new cell to replace the empty cell
				if (count == 3)
				{
					cpy[x][y] = 1;
				}
			}
		}	
//copies array back to original, neighbors checked, rules applied
for(int x = 0; x < ROWS; x++)
		{
			for(int y = 0; y < COLS; y++)
			{
				d[x][y] = cpy[x][y];
			}

		}
replay(d);
}
/***********************************************************************************
*Description: userInput fn, prompts user for initial coordinates.
*Parameters: passes user selection for coordinates and weapon to board initializer
***********************************************************************************/
void userInput()
{
	int x, y, choice;
	cout << "What are the coordinates that you would like to begin with?\n";
	cin  >> x >> y; 

	cout << "What pattern would you like to begin with?\n";
	cout << "1. Glider Pattern\n";
	cout << "2. Glider Gun\n";
	cout << "3. Cannon Pattern\n";
	cin  >> choice;

	if(choice == 1)
	{
		initBoard(x, y, 1);
	}
	if(choice == 2)
	{
		initBoard(x, y, 2);
	}
	if(choice == 3)
	{
		initBoard(x, y, 3);
	}

}
/***********************************************************************************
*Description: replay fn, asks user if they would like to re-run the program. 
*Parameters: 
***********************************************************************************/
void replay(int e[ROWS][COLS])
{
	char response;
	cout << "Would you like to continue running the program? y/n\n";
	cin  >> response;

	if((response == 'Y') || (response == 'y'))
		{
			dispBoard(e);
		}	
	else
		cout << "Game Over " << endl;
		return;
}



























