/***********************************************************************************
*Filename: Transform.cpp
*Name: John R Toth
*Date: 4/29/15
*Description: Transform implementation file
*Input: None
*Output: Copy of ifstream file, transformed to uppercase letters
***********************************************************************************/

#include "FileFilter.hpp"

void Transform::doFilter(ifstream &inValue, ofstream &outValue, string &inputFile, string &outputFile)
{
	
	char input;
	char ch;


	inValue.open(inputFile.c_str(), ios::in);
	outValue.open(outputFile.c_str(), ios::out | ios::app);

	if(inValue)
	{
		inValue.get(input);
		while(!inValue.fail())
			{
			if((input >= 'A') && (input <= 'Z'))
				{
				outValue << input;
				}

				else if((input >= 'a') && (input <='z'))
					{
				
					ch = transform(input);	
					outValue << ch; 
					}

					else if((input == ' ') || (input == '.'))
						{	
						outValue.flush();
						outValue << input;
						}
					
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

char Transform::transform(char ch)
{
 ch -= 32;

return ch;
}






