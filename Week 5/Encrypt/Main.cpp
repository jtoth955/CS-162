/***********************************************************************************
*Filename: Main.cpp
*Name: John R Toth
*Date: 4/29/15
*Description: Main implementation file 
*Input: Prompts user for ifstream and ofstream filenames
*Output: Displays menu of single run options for a user to select
***********************************************************************************/

#include "FileFilter.hpp"

#include <fstream> 
#include <iostream> 
#include <string> 

using namespace std; 

int main() 
{

	int choice;	
	ifstream inValue; 
	ofstream outValue;
	string inputFile, outputFile;
	
	cout << "Please enter the name of the first input file: ";
	cin  >>inputFile;

	cout << "Please enter the name of the output file: ";
	cin  >>outputFile;



		cout << "\n 		Please make a selection						\n\n";
		cout << "1. Create an unchanged copy\n";
		cout << "2. Encrypt message\n";
		cout << "3. Transform message to uppercase letters\n";
		cout << "4. Special\n"; 
		cout << "5. Exit\n";
		cin  >> choice; 

			if (choice == 1)
				//create an unchanged copy
			{
				Copy cpyObj;
				FileFilter *ff = &cpyObj;
				ff->doFilter(inValue, outValue, inputFile, outputFile);
			}
			else if(choice == 2)
				//Encrypt message
			{
				Encrypt encObj;
				FileFilter *ff = &encObj;
				ff->doFilter(inValue, outValue, inputFile, outputFile);
			}
			else if(choice == 3)
				//Transform to uppercase
			{
				Transform transObj;
				FileFilter *ff = &transObj;
				ff->doFilter(inValue, outValue, inputFile, outputFile);
			}
			else if (choice == 4)
				//Special 
			{
				Special specObj;
				FileFilter *ff = &specObj;
				ff->doFilter(inValue, outValue, inputFile, outputFile);
			}
			else if ((choice < 1)||(choice > 5))
			{
				cout << "The valid choices were 1-4\n" << endl;
			}



	return 0;
}