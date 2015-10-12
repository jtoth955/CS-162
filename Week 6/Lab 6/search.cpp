/***********************************************************************************
*Filename: Search.cpp
*Name: John R Toth
*Date: 5/6/15
*Description: Program that locates the value '0' and relays it's location to screen
*Input: Input file name 
*Output: Location of the value '0' to screen
***********************************************************************************/

#include <fstream> 
#include <iostream> 
#include <vector> 
#include <string> 

using namespace std;

//fn prototype
char searchList(vector<char>);


int main () 
{

	int results;	
	char input; 
	vector<char> search;
	ifstream inValue; 
	string inputFile;

	cout << "Please enter the name of the input file: ";
	cin  >>inputFile;

	inValue.open(inputFile.c_str(), ios::in);

	if(inValue)
	{
		inValue.get(input);
		inValue.clear();
		inValue.seekg(0L, ios::beg);

		while(!inValue.fail()) 
		{
			inValue >> input;
			if(inValue.fail()) break;
			search.push_back(input);
		}
	
	}
	else
		{
			cout << "Error opening the input file." << endl;
				inValue.close();
		}

	results = searchList(search);

	//if seachList returned -1, 0 was not found
	if(results == -1 )
		cout << results << endl;

		else 
		{
			cout << "Zero was found at position: ";
			cout << (results + 1) << endl;
		}


	return 0;
}

/***********************************************************************************
*Description: searchList function, locates and relays position, if value is present
*Parameters: vector of char 
***********************************************************************************/

char searchList(vector<char> vect)
{
	
	char value = '0';
	int position = -1;
	bool found = false;

	for(int count = 0; count < vect.size(); count++)
	{
	
		if(vect[count] == value)
			{
				found = true; 
				position = count;
			}		
		
	}
	
	return position;

}













