/************************************************************************************
*Filename: Main.cpp
*Name: John R Toth
*Date: 4/26/15
*Description: Shopping cart program, creates shopping list, removes items and displays
*shopping cart contents, both regular priced and sales items
*Input: User selects intention on main menu, given the four available options. 
*Output: Displays menu with four options. 
************************************************************************************/

#include "List.hpp"
#include "ClubItems.hpp"
#include "Items.hpp"

#include <iostream> 

using namespace std; 

/*********************************************************************************
*Main fn 
*displays do-while loop menu  
*********************************************************************************/
int main () 
{

	int choice;
	
	//object declarations 
	Items itemObj;
	List  listObj;

	do{
		//Display the menu and get the user's choice
	cout << "\n                         Welcome to your local grocer                           \n\n";
	cout << "1. Create a list\n"; 
	cout << "2. Remove Items\n"; 
	cout << "3. Display Shopping List\n";
	cout << "4. Exit\n";
	cin  >> choice;

			if(choice == 1)
			//create a list
			{
				listObj.addProduct();
			}
			else if(choice == 2)
			//remove items
			{
				listObj.remove();
				
			}
			else if(choice == 3)
			//display shopping list
			{
				listObj.displayList();
			}
			else if(choice > 4)
			//error message
			{
				cout << "\nThe valid choices are 1 - 4\n" << endl;
			}

	}while(choice != 4);

return 0;
}

















