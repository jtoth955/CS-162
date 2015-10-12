/***********************************************************************************
*Filename: Lab1.1.cpp
*Name: John R Toth
*Date: 4/1/15
*Description: Fn that takes threee pointers as arguments, then sorts, smallest to 
*largest 
*Input: User supplies 3 random values
*Output: Displays users 3 values, sorted from smallest to largest 
***********************************************************************************/

#include <iostream> 
using namespace std; 

//sortValue prototype fn, takes 3 int values as pointers, then sorts values from smallest 
//to largest
void sortValue (int *, int *, int *); 

//main fn, asks user to input 3 integers, displays those values then calls sortValue fn
int main()
{
	int num1, num2, num3; 

	cout << "\nInput 3 integer values:\n" << endl; 
	cin  >> num1 >> num2 >> num3; 

	int *p1 = &num1, 
		*p2 = &num2, 
		*p3 = &num3;

	cout << "\nYour unsorted values are:\n" << *p1 <<",\n"<< *p2 <<",\n"<< *p3 << endl;

		sortValue(&num1, &num2, &num3);

	return 0; 
}
/***********************************************************************************
*Description: sortValue fn, receives three pointer values and sorts from smallest to 
*largest
*Parameters: None
***********************************************************************************/

void sortValue (int *val1, int *val2, int *val3)
{
	int temp; 

	if(*val1 > *val2)
		{
			temp = *val1;
			*val1 = *val2;
			*val2 = temp;
		}
	if(*val1 > *val3)
		{
			temp = *val1; 
			*val1 = *val3;
			*val3 = temp; 
		}
	if(*val2 > *val3)
		{
			temp = *val2; 
			*val2 = *val3;
			*val3 = temp; 
		}	
//display re-ordered values
cout << "\nYour sorted values are:\n" << *val1 << ", " << endl << *val2 << ", "
	 << endl << *val3 << endl;

}
