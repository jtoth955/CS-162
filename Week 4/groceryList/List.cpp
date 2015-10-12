1/************************************************************************************
*Filename: List.cpp
*Name: John R Toth
*Date: 4/26/15
*Description: List implementation file. 
*Input: Requires input from users, including whether or not they're club members, the 
*name, size, amount, and price of object. Also prompts user to define whether or not 
*product was a sales item, so long as they are club members. Also includes remove fn. 
*Output: Displays current shopping list, subtotals and totals for current excursion.
************************************************************************************/

#include "List.hpp"
#include "ClubItems.hpp"
#include "Items.hpp"

#include <iostream> 
#include <iomanip>


using namespace std; 

//default constructor
List::List() {
	product.reserve(100);
}
//Product vector, takes user input to create a Product object
void List::addProduct() {
	char member, again, sale;
	string name;
	int quantity;
	double size, price;

	cout << "Are you a Club Member? (y/n)" << endl;
	cin  >> member; 
do {
	
if((member == 'y')||(member == 'Y'))
{	

	cin.ignore();
	cout << "Please enter the name of the product: " << endl;
	getline(cin, name); 

	cout << "Please enter the size of the product, in ounces: " << endl;
	cin  >> size; 

	cout << "Plese enter the number that you would like to purchase: " << endl;
	cin  >> quantity; 

	cout << "Please enter the price of the product: " << endl;
	cin  >> price; 

		cout << "Was this item on sale? (y/n) ";
		cin  >> sale;
	
		if((sale == 'y')||(sale == 'Y'))
		{		

		//add to discounted vector if on sale

		ClubItems discProduct(name, size, quantity, price, sale);
		discount.push_back(discProduct);
		
		}	

		else
		{
		//add to regular price vector if not on sale
		
		Items newProduct(name, size, quantity, price, sale);
		product.push_back(newProduct);

		}
		cout << "Would you like to add more items? ";
		cin  >> again;
	
}
else 
{
	cin.ignore();
	cout << "Please enter the name of the product: " << endl;
	getline(cin, name); 

	cout << "Please enter the size of the product, in ounces: " << endl;
	cin  >> size; 

	cout << "Plese enter the number that you would like to purchase: " << endl;
	cin  >> quantity; 

	cout << "Please enter the price of the product: " << endl;
	cin  >> price;	

	//add to regular price vector if not on sale
	Items newProduct(name, size, quantity, price, sale);
	product.push_back(newProduct);

	cout << "Would you like to add more items? ";
	cin  >> again;
}

}while ((again =='Y')||(again == 'y'));
	
}
//remove items
void List::remove() 
{
	
	char choice; 
	cout << "Would you like to remove full priced items? (y/n)\n";
	cin  >> choice;

	if((choice == 'y')||(choice == 'Y'))
	{
		if(product.empty())
		{
		cout << "\nThere are no items to remove.\n";
		return;
		}
		
		else
		{
		product.pop_back();
		cout << "Ok, full price item removed. " << endl;
		}
	}
	else if((choice == 'n')||(choice == 'N'))
	{
		
		if(discount.empty())
		{
		cout << "\nThere are no sales items to remove.\n";
		return;
		}
		
		else
		{	
		discount.pop_back();
		cout << "Ok, sale item removed. " << endl;
		}
	}
	else
	{
		cout << "Sorry, I didn't understand your input. " << endl;
	}
}

//display shopping list
void List::displayList() 
{

	cout << "\n*" << "Denotes sales items." << endl;
	for(int x = 0; x < product.size(); x++)
	{
		cout << product[x].Items::getName() << ", ";
		cout << product[x].Items::getSize() << " ounces, ";
		cout << product[x].Items::getQuantity() << " unit(s), ";
		cout << "$" << fixed << setprecision(2) << product[x].Items::getPrice() << endl;
	
	} 

	if(product.empty())
		cout << "\nThere are no regular priced items to display\n" << endl;


	for(int y = 0; y < discount.size(); y++)
	{
		cout << fixed << setprecision(0);
		cout << discount[y].ClubItems::getName() << ", ";
		cout << discount[y].ClubItems::getSize() << " ounces, ";
		cout << discount[y].ClubItems::getQuantity() << " unit(s), ";
		cout << "$" << fixed << setprecision(2) << discount[y].ClubItems::getPrice() << "*" << endl;

	}

	if(discount.empty())
		cout << "\nThere are no sale items to display\n";

	displayTotal();
}

//disply total for this shopping list instance
void List::displayTotal() {
	double sum, total; 

	//determine if regular price items are in basket, display error if not
	if(product.empty())
		cout << endl;

	else{
	for(int x = 0; x < product.size(); x++)
	{
		sum += product[x].Items::getPrice() * product[x].Items::getQuantity();
	}	 
	cout << fixed << setprecision(2) << "\nYour regular priced items total for this shopping list is: " << "$" << sum << endl;
}
	
	//determine if sales items are in basket, display error if not
	if(discount.empty())
		return;

	else{
	//calculate and display sale priced items
	for(int y = 0; y < discount.size(); y++)
	{
		total += discount[y].ClubItems::getPrice() * discount[y].ClubItems::getQuantity();
	}	 
	cout << fixed << setprecision(2) << "\nYour sales priced items total for this shopping list is: " << "$" << total << endl;
	}

	//display total amount for this excursion
	cout << fixed << setprecision(2) << "\nTotal amount for this shopping list is: " << "$" << total+sum << endl;

}












