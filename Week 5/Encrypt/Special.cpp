/***********************************************************************************
*Filename: Special.cpp
*Name: John R Toth
*Date: 4/29/15
*Description: Special implementation file
*Input: User defined offset value of cipher
*Output: Cipher shifted copy of ifstream file, output to ofstream file, printed in 
*blocks of 5
***********************************************************************************/

#include "FileFilter.hpp"

void Special::doFilter(ifstream &inValue, ofstream &outValue, string &inputFile, string &outputFile)
{

	int keyVal;
	int count = 0; 
	char input, ch; 

	cout << "What is the offset value? " << endl;
	cin  >> keyVal;

	inValue.open(inputFile.c_str(), ios::in);
	outValue.open(outputFile.c_str(), ios::out | ios::app);

	if(inValue)
	{
		inValue.get(input);
		while(!inValue.fail())
			{

			if(count == 6)
				{
				ch = jump(input); 
				outValue.flush();
				count = 0;
				outValue << ch;				
				}
			
				else if(count < 6)
					{
					ch = transform(input, keyVal);
					inValue.get(input);
					outValue.flush();
					outValue << ch;
					}	
					
					++count;
			}
	
	}
	
		else
		{
			cout << "Error opening the input file. " << endl;
				inValue.close();
				outValue.close();
		}
}

char Special::transform(char ch, int key)
{
	key %= 26;

		if((ch >='A') && (ch <= 'Z'))
			{
				ch += key;
				return ch;
			}

			else if((ch >='a') && (ch <'z'))
				{
					ch -= (32 - key);
					return ch;				
				}
			
				else if((ch == ' ') || (ch == ','))
					{
						return 0; 
					}

					else if(ch == '.')
						{
							return 0; 
						}

	return ch;

}	

char Special::jump(char ch)
{

	ch = ' '; 
	return ch; 
}




