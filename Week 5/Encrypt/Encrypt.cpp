/***********************************************************************************
*Filename: Encrypt.cpp
*Name: John R Toth
*Date: 4/29/15
*Description: Encrypt implementation file
*Input: User defined offset value of cipher
*Output: Cipher shifted copy of ifstream file, output to ofstream file
***********************************************************************************/

#include "FileFilter.hpp"

void Encrypt::doFilter(ifstream &inValue, ofstream &outValue, string &inputFile, string &outputFile)
{
	int keyVal;
	char input, ch;

	cout << "What is the offset value? " << endl;
	cin  >> keyVal; 
	
	inValue.open(inputFile.c_str(), ios::in);
	outValue.open(outputFile.c_str(), ios::out | ios::app);

	if(inValue.get(input))
		while(!inValue.fail())
		{

			if((input == ' ')||(input == '.'))
			{
				outValue << input;
			}

				else if(input == ',')
				{
					outValue << input;
				}

					else 
					{
						ch = transform(input, keyVal);
						outValue.flush();
						outValue << ch;
					}
						inValue.get(input);
		}
	
		else
		{
			cout << "Error opening the input file." << endl;
				inValue.close();
				outValue.close();
		}

}

char Encrypt::transform(char ch, int key)
{
	key %= 26;
	ch += key;

	return ch;
}

