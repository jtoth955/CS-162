/***********************************************************************************
*Filename: Copy.cpp
*Name: John R Toth
*Date: 4/29/15
*Description: Copy implementation file
*Input: None
*Output: Exact copy of ifstream file, output to ofstream file
***********************************************************************************/


#include "FileFilter.hpp"

void Copy::doFilter(ifstream &inValue, ofstream &outValue, string &inputFile, string &outputFile)
{
	char input;


	inValue.open(inputFile.c_str(), ios::in);
	outValue.open(outputFile.c_str(), ios::out | ios::app);
	
	if(inValue)
	{
		
		inValue.get(input);
		while(!inValue.fail())
		{
			outValue << input;
			outValue.flush();
			inValue.get(input);
		}

	}
			else
			{
				cout << "Error opening the input file. " << endl;
					inValue.close();
					outValue.close();
			}

}
