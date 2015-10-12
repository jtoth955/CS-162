/***********************************************************************************
*Filename: Main.cpp
*Name: John R Toth
*Date: 5/4/15
*Description:
*Input: 
*Output:   
***********************************************************************************/

#include "Character.hpp"
#include "Arena.hpp"
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "Blue.hpp"
#include "Shadow.hpp"
#include "Goblin.hpp"

#include <iostream> 
#include <cstdlib> 
#include <ctime>

using namespace std; 

	Barbarian barb1;
	Reptile rep1;
	Blue blu1;
	Shadow shad1;
	Goblin gob1;


//fn prototypes
void role();
void fightingRing(int, int, int);
int player(); 
int opponent();
bool validate(int);
void fight(int);
void defend(int);
void goAgain();


/*********************************************************************************
*Main fn 
*displays do-while loop menu  
*********************************************************************************/
int main () 
{

	
	unsigned seed;
	seed = (time(0));
	srand(seed);

	role();
	goAgain();




return 0;
}

void role()
{ 
	int player1;
	int player2;
	int choice;
	

	player1 = player();
	player2 = opponent();


		//role the menu and get the user's choice
	cout << "\n                         Let's get ready to RUMBLE!                           \n\n";
	
	cout << "\nWhat role will your player take?\n\n"; 
	
	cout << "1. Attack\n"; 
	cout << "2. Defend\n"; 
	
	cin  >> choice;

	if(choice > 3)
	{
		cout << "\nThe valid choices are 1 - 3. Try again.\n" << endl;
		role();
	}
	
	if((choice == 1)||(choice == 2))
	{
		fightingRing(player1, player2, choice);
	}

}
/*********************************************************************************
*Description - FightingRing fn that uses a Do-while loop menu that calls the 
*attack and defend fns, then asks user if they want to continue fighting or exit.
*Parameters - fn receives players selected character, their opponent and the role 
*that the user wants to assume
*********************************************************************************/
void fightingRing(int player1, int opponent, int role)
{
	int choice; 
	bool alive = true;

	do
	{
			
		cout << "\n                      	     THE BATTLE IS ON!!!                           \n\n";
		
		if(role == 1)
		{
			fight(player1);
			defend(opponent);
		}
		else if(role == 2)
		{
			fight(opponent);
			defend(player1); 
		}
		cout << endl;
		
		alive = validate(player1);
		alive = validate(opponent);

			if(alive == false)
			{
				goAgain(); 					
			}

			if(alive == true)
			{
				cout << "1. Continue Fighting?\n"; 
				cout << "2. Exit\n"; 
				cin  >> choice;
			}
	
			if(choice > 2)
				cout << "Valid response is 1 or 2. Try again. " << endl;

	
	}	while(choice != 2);
		

}
/*********************************************************************************
*Description - Player fn that asks user which character they would like to be, 
*then calls validate fn to ensure character is still alive
*********************************************************************************/
int player()
{
	int player1;
	bool valid, alive;

	
		cout << "What character would you like to be? " << endl;
		
		alive = validate(1);
		if( alive == true)
		{
			cout << "1. Goblin\n"; 
		}
		else
		{
			cout << "1. Goblin - dead\n";
		}
			alive = validate(2);
			if(alive == true)
			{
				cout << "2. Barbarian\n";
			}
			else
			{
				cout << "2. Barbarian - dead\n";
			}
				alive = validate(3);
				if(alive == true)
				{
					cout << "3. Reptile Man\n";
				}
				else
				{
					cout << "3. Reptile Man - dead\n";
				}
					alive = validate(4);
					if(alive == true)
					{
						cout << "4. Blue Man\n";	
					}
					else
					{
						cout << "4. Blue Man - dead\n";
					}
						alive = validate(5);
						if(alive == true)
						{
							cout << "5. The Shadow\n";	
						}
						else
						{
							cout << "5. The Shadow - dead\n";
						}
		 
						cin  >> player1; 

							
							if(player1 > 5)
							{
								cout << "Valid response is 1-6. Please try again.\n" << endl;
								player();
							}
			
								//check to ensure the chosen character is still alive
								valid = validate(player1);
								if(valid == false)
								{
									player(); 
								}
			
	return player1;

}
/*********************************************************************************
*Description - Opponent fn that asks user who their opponent should be, then 
*calls the validate fn to ensure the selected character is alive  
*********************************************************************************/
int opponent()
{
	int player2;
	bool valid, alive;

		cout << "Who will be your opponent? " << endl;
		
		alive = validate(1);
		if( alive == true)
		{
			cout << "1. Goblin\n"; 
		}
		else
		{
			cout << "1. Goblin - dead\n";
		}
			alive = validate(2);
			if(alive == true)
			{
				cout << "2. Barbarian\n";
			}
			else
			{
				cout << "2. Barbarian - dead\n";
			}
				alive = validate(3);
				if(alive == true)
				{
					cout << "3. Reptile Man\n";
				}
				else
				{
					cout << "3. Reptile Man - dead\n";	
				}
					alive = validate(4);
					if(alive == true)
					{
						cout << "4. Blue Man\n";	
					}
					else
					{
						cout << "4. Blue Man - dead\n";
					}
						alive = validate(5);
						if(alive == true)
						{
							cout << "5. The Shadow\n";	
						}
						else
						{
							cout << "5. The Shadow - dead\n";
						}
						  
						cin  >> player2;

							if(player2 > 5)
							{
								cout << "Valid response is 1-6. Please try again.\n" << endl;
								opponent();
							}

								//check to ensure the chosen character is still alive
								valid = validate(player2);
								if(valid == false)
								{
									opponent();
								}
						
					
	return player2;

}
/*********************************************************************************
*Description - Validate fn that receives player and opponent characters and checks 
*to ensure the character is still alive. False is returned if dead, true otherwise
*Parameter - user selected character
*********************************************************************************/
bool validate(int character)
{
	bool check;

	//check if Goblin is still alive
	if(character == 1)
		{
		if(gob1.getStatus() == false)
			{
				check = false;
				return check;
			}
			else if(gob1.getStatus() == true) 
			{
				check = true; 
				return check;
			}
		}	

				//check if Barbarian is still alive
				if(character == 2)
					{
					if(barb1.getStatus() == false)
						{
							check = false;
							return check;
						}
					else if(barb1.getStatus() == true) 
						{
							check = true; 
							return check;
						}
					}

						//check if Reptile People are still alive
						else if(character == 3)
							{
							if(rep1.getStatus() == false)
								{
									check = false;
									return check;
								}
							else if(rep1.getStatus() == true) 
								{
									check = true; 
									return check;
								}	
							}	
							
							//check if Blue Men are still alive
							else if(character == 4)
								{
								if(blu1.getStatus() == false)
									{
										check = false;
										return check;
									}
								else if(blu1.getStatus() == true) 
									{
										check = true; 
										return check;
									}
								}		
									
									//check if The Shadow is still alive
									else if(character == 5)
										{
										if(shad1.getStatus() == false)
											{
												check = false;
												return check;
											}
										else if(shad1.getStatus() == true) 
											{	check = true; 
												return check;
											}
										}	
	
	return check;

}
/*********************************************************************************
*Description - Fight fn that properly stages players so that attacker always makes 
*the first move
Parameter - user selected fighter
*********************************************************************************/
void fight(int fighter)
{

		if(fighter == 1)
		{
			Character *chr = &gob1;
			chr->attack();
		}
		
		else if(fighter == 2)
		{
			Character *chr = &barb1;
			chr->attack();
		}
		
		else if(fighter == 3)
		{
			Character *chr = &rep1;
			chr->attack();
		}
		
		else if(fighter == 4)
		{
			Character *chr = &blu1;
			chr->attack();
		}
		
		else if(fighter == 5)
		{
			Character *chr = &shad1;
			chr->attack();
		}

}
/*********************************************************************************
*Description - Defend fn that aids the fight fn, ensuring that attacker always 
*makes the first move
*Parameter - user selected defender
*********************************************************************************/
void defend(int defender)		
{

		if(defender == 1)
		{
			Character *chr = &gob1;
			chr->defense();
		}

		else if(defender == 2)
		{
			Character *chr = &barb1;
			chr->defense();
		}
		
		else if(defender == 3)
		{
			Character *chr = &rep1;
			chr->defense();
		}
		
		else if(defender == 4)
		{
			Character *chr = &blu1;
			chr->defense();
		}
		else if(defender == 5)
		{
			Character *chr = &shad1;
			chr->defense();
		}

}
/*********************************************************************************
*Description - goAgain fn Loop fn that asks the user if they would like to play 
*again or exit. 
Paramters - User input
*********************************************************************************/
void goAgain()
{
	int choice;

	do
	{
		//display the menu and get the user's choice

	cout << endl;
	cout << "\nWould you like to play again??\n\n"; 
	
	cout << "1. Let's Play!\n"; 
	cout << "2. Exit\n"; 
	cin  >> choice;

			if(choice == 1)
			{
				role();	
			}
			
			else if(choice > 2)
			{
				cout << "\nThe valid choices are 1 or 2\n" << endl;
			}

	}	while(choice != 2);

}







