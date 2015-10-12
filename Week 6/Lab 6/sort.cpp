/***********************************************************************************
*Filename: Sort.cpp
*Name: John R Toth
*Date: 5/6/15
*Description: Program that sorts input file and prints sorted list to output file
*Input: Input file name 
*Output: Users input file, sorted 
***********************************************************************************/

#include <fstream> 
#include <iostream> 
#include <vector> 
#include <string> 

using namespace std;

//fn prototype
void sortList(vector<char> &);
void printList(vector<char>, ofstream &outValue, string &outputFile);

int main () 
{
	
	char input;
	vector<char> sort;
	ifstream inValue; 
	ofstream outValue;
	string inputFile;
	string outputFile;

	cout << "Please enter the name of the input file: ";
	cin  >>inputFile;

	cout << "Please enter the name of the output file: ";
	cin  >>outputFile;

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
			sort.push_back(input);
		}
	
	}
	else
		{
			cout << "Error opening the input file." << endl;
				inValue.close();
				outValue.close();
		}

	sortList(sort);
	printList(sort, outValue, outputFile);

	return 0;
}

/***********************************************************************************
*Description: sortList fn, takes vector of char values and sorts user values
*Parameters: vector of char
***********************************************************************************/

void sortList(vector<char> &vect)
{
	char temp;
	bool complete = false;

	while(!complete)
	{
		complete = true;

		for(int index = 0; index < vect.size()-1; index++)
		{
	
			if(vect[index] > vect[index+1])
			{
				temp = vect[index];
				vect[index] = vect[index+1];
				vect[index+1] = temp;
				complete = false;
			}		
		
		}
		
	}	
	
}

/***********************************************************************************
*Description: printList fn, takes vector of char values and sends to user defined
* output file.
*Parameters: vector of char, ofstream file name 
***********************************************************************************/

void printList(vector<char> print, ofstream &outValue, string &outputFile)
{
	outValue.open(outputFile.c_str(), ios::out | ios::app);

		for(int i = 0; i < print.size(); i++)
		{
			outValue << print[i] << "  ";

		}
		outValue << endl;
			
			cout << "Your sorted list has been sent to: " << outputFile << endl;
}











