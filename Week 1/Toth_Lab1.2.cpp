/************************************************************************************
*Filename: Lab1.2.cpp
*Name: John R Toth
*Date: 4/3/15
*Description: Object oriented program that calls separate cpp files to display a 
*message  
*Input: None
*Output: Message from main
************************************************************************************/

#include <iostream> 

#include "f.cpp"
#include "g.cpp"

using namespace std; 

int main() 
{ 

	cout << "This message originated in main. " << endl;

	//display message from F
	fMessage();

	//display message from G
	gMessage(); 

return 0; 
}

