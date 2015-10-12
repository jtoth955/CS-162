/***********************************************************************************
*Filename: Sort.cpp
*Name: John R Toth
*Date: 4/22/15
*Description: Main Fn that merges and sorts two files and writes to a third file  
*Input: User supplies name of the two input files and output file
*Output: Sorted merge of two files into an output-file. 
***********************************************************************************/

#include <iostream>
#include <string> 
#include <fstream>  

using namespace std;

int main() 
{
	ifstream inValue1, inValue2; 
	ofstream outValue;
	string inputFile1, inputFile2, outputFile; 
	int input1, input2, length;

	
	cout << "Please enter the name of the first input file: ";
	cin  >>inputFile1;
	inValue1.open(inputFile1.c_str(), ios::in);

	cout << "Please enter the name of the second input file: ";
	cin  >>inputFile2;
	inValue2.open(inputFile2.c_str(), ios::in);

	cout << "Please enter the name of the output file: ";
	cin  >>outputFile;
	outValue.open(outputFile.c_str(), ios::out | ios::app);


if(inValue1)
{

	if(inValue2)
	{

//read first and second input file, compare, sort and store in output file
inValue1 >> input1;
inValue2 >> input2;

while ((!inValue1.eof())&&(!inValue2.eof()))		
{

		if(input1 < input2)
		{
		outValue << input1 << endl;
		inValue1 >> input1;
		}	
				
		else if(input2 < input1)
		{
		outValue << input2 << endl;		
		inValue2 >> input2;
		}

		else if(input2 == input1)
		{		
		inValue2 >> input2;
		}

		if((inValue1.eof()) && (!inValue2.eof()))
		{
			while(inValue2 >> input2)
			{
			outValue << input2 << endl;	
			}	
		}
		if((inValue2.eof()) && (!inValue1.eof()))
		{	
			while(inValue1 >> input1)
			{
				outValue << input1 << endl;	
				
			}	
		}
	}
}
else
	{
	cout << "Error opening the second input file.\n";
	}
}	
else
	{
	cout << "Error opening the first input file.\n";
	}


//check to see if there are values in the first file, print second file if not. 
inValue1.seekg(0, ios::end);
length = inValue1.tellg();
inValue1.clear(); 
inValue1.close(); 

if(length <= 2)
{
	inValue2 >> input2;
	
	while (!inValue2.eof())
	{
		outValue << input2 << endl;
		inValue2 >> input2;
	}
}	

return 0;	
}







